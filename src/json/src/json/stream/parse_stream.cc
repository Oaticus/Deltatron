#include <dt/json/stream.hh>
#include <dt/json/container_imp.hh>
#include <dt/json/error.hh>

#include <string>

namespace dt {

class parse_state final {
public:
	using const_pointer = token::stream_type::const_pointer;

private:
	std::string 			 const& _id;
	token::stream_type const& _stream;
	const_pointer			 const  _end;
	const_pointer 						_current_token;

public:
	parse_state(std::string const& i, token::stream_type const& s) noexcept
	: _id(i),
		_stream(s),
		_end(s.data() + s.size()),
		_current_token(s.data()) {}

	constexpr auto operator->() const noexcept { return _current_token; }

	constexpr auto eof() const noexcept { return _current_token >= _end; }

	constexpr auto distance() const noexcept { return _end - _current_token; }

	constexpr void try_increment()
	{ ++_current_token; if (eof()) throw json_error(_id, (_end - 1)->line(), "reached end of file while evaluating json data"); }

	[[noreturn]] void throw_exception(char const* message) const
	{ throw json_error(_id, eof() ? (_end - 1)->line() : _current_token->line(), message); }
};

object_type parse_object(parse_state&);

array_type parse_array(parse_state& state) {
	if (!state->has_type(token_type::LBrack))
		state.throw_exception("expected open bracket");

	state.try_increment();

	array_type array{};

	if (state->has_type(token_type::RBrack))
		return array;

	while (!state.eof()) {
		if (state->has_value())
			array.push_back(json_container_imp(state->value()));
		else if (state->has_type(token_type::LBrace))
			array.push_back(json_container_imp(parse_object(state)));
		else if (state->has_type(token_type::LBrack))
			array.push_back(json_container_imp(parse_array(state)));
		else
			state.throw_exception("expected array value entry");

		state.try_increment();

		if (!state->has_type(token_type::Comma)) {
			if (!state->has_type(token_type::RBrack))
				state.throw_exception("expected comma or end of array");

			break;
		}

		state.try_increment();
	}

	if (state.eof())
		state.throw_exception("reached end of file while evaluating array");

	return array;
}

object_type parse_object(parse_state& state) {
	if (!state->has_type(token_type::LBrace))
		state.throw_exception("expected open brace");

	state.try_increment();

	if (state->has_type(token_type::RBrace))
		return {};

	object_type object{};

	while (!state.eof()) {
		if (!state->has_type(token_type::String))
			state.throw_exception("expected end of object or object value key");

		auto const key = state->value_as<std::string>().value();

		state.try_increment();

		if (!state->has_type(token_type::Colon))
			state.throw_exception("expected colon after string key");

		state.try_increment();

		if (state->has_value())
			object.try_emplace(key, json_container_imp(state->value()));
		else if (state->has_type(token_type::LBrace))
			object.try_emplace(key, parse_object(state));
		else if (state->has_type(token_type::LBrack))
			object.try_emplace(key, parse_array(state));
		else
			state.throw_exception("expected object key definition");

		state.try_increment();

		if (!state->has_type(token_type::Comma)) {
			if (!state->has_type(token_type::RBrace))
				state.throw_exception("expected comma or end of object");

			break;
		}

		state.try_increment();
	}

	return object;
}

json_container_imp parse_stream(std::string const& id, token::stream_type const& stream) {
	if (stream.empty())
		return {};

	auto state       = parse_state(id, stream);
	auto root_value  = json_container_imp::value_type();

	switch(state->type()) {
    case token_type::LBrace:	root_value = parse_object(state); break;
    case token_type::LBrack:  root_value = parse_array(state);  break;
    case token_type::String:  [[fallthrough]];
    case token_type::Integer: [[fallthrough]];
    case token_type::Float:   [[fallthrough]];
    case token_type::Bool:    [[fallthrough]];
    case token_type::Null:		root_value = state->value(); break;
		default:
			state.throw_exception("invalid root value");
	}

	if (state.distance() > 1)
		state.throw_exception("multiple root values detected");

	return root_value;
}

}
