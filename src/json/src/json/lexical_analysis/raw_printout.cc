#include <dt/json/lexical_analysis/token.hh>

#include <iostream>

void dt::dbg::raw_printout(token::stream_type const& stream) noexcept {
	std::cout << "--- Raw printout of token stream ---" << std::endl;

	for (auto const& token : stream) {
		switch (token.type()) {
			case token_type::Colon:   [[fallthrough]];
			case token_type::Comma:   [[fallthrough]];
			case token_type::LBrace:  [[fallthrough]];
			case token_type::RBrace:  [[fallthrough]];
			case token_type::LBrack:  [[fallthrough]];
			case token_type::RBrack:  std::cout << enum_to_char(token.type()) << ' '; break;
			case token_type::String:  std::cout << "String:\"" << token.value_as<std::string_view>().value() << "\" "; break;
			case token_type::Integer: std::cout << "Integer:" << token.value_as<std::int32_t>().value() << ' '; break;
			case token_type::Float:   std::cout << "Float:" << token.value_as<float>().value() << ' '; break;
			case token_type::Bool:    std::cout << std::boolalpha << "Bool:" << token.value_as<bool>().value() << ' '; break;
			case token_type::Null:    std::cout << "Null ";
		}
	}

	std::cout << std::endl << "--- End of raw printout of token stream ---" << std::endl;
}
