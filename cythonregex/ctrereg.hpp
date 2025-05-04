#include "ctre-unicode.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std::literals;

typedef struct result {
	int64_t position;
	int64_t length;
	std::string match;
} result;

static std::vector<result> all_matches_to_vector(auto& original, auto& all_matches) {
	std::vector<result> results;
	size_t start_address{ (size_t)original.data() };
	for (auto& match : all_matches) {
		size_t address{ (size_t)match.data() };
		results.emplace_back(result{ (int64_t)(address - start_address), (int64_t)(match.to_view().length()), {match.to_view().begin(), match.to_view().end()} });
	}
	return results;

}

static std::u8string convert_address_to_string(size_t addr_input) {
	const char* char_input{ (const char*)addr_input };
	std::string_view input(char_input);
	return { input.begin(), input.end() };
}

std::vector<result> find_ip_addresses(size_t addr_input) {
	std::u8string original{ convert_address_to_string(addr_input) };
	auto all_matches{ ctre::search_all<u8"\\b(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[1-9])\.)(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){2}(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\b">(original) };
	return all_matches_to_vector(original, all_matches);
}

