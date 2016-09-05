#pragma once

#include <string>

namespace TestTools
{
	struct testGtf;
	struct testGeneMerge;
}

namespace Tools
{
	class GeneInfo
	{
		friend struct TestTools::testGtf;
		friend struct TestTools::testGeneMerge;
	public:
		typedef unsigned int num_t;
		typedef unsigned long pos_t;

	private:
		std::string _chr_name = "";
		std::string _id = "";
		pos_t _start_pos;
		pos_t _end_pos;

	public:
		GeneInfo() = default;
		GeneInfo(const std::string &chr_name, std::string id, pos_t start_pos, pos_t end_pos);

		std::string chr_name() const;
		std::string id() const;
		pos_t start_pos() const;
		pos_t end_pos() const;
		pos_t size() const;

		bool is_valid() const;
		void merge(const GeneInfo &other);
		bool is_intercept(const GeneInfo &other) const;

		bool operator<(const GeneInfo &other) const;
	};
}