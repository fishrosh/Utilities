#pragma once

namespace vip
{
	template <typename _Ty>
	void swapperator(_Ty& l, _Ty& r) noexcept
	{
		auto a = (unsigned char*)&l;
		auto b = (unsigned char*)&r;

		for (size_t i = 0ull; i < sizeof(_Ty); ++i)
		{
			a[i] ^= b[i];
			b[i] ^= a[i];
			a[i] ^= b[i];
		}
	}

	template <typename _Ty>
	struct batch
	{
		_Ty const* const data;
		size_t const size;

		batch(_Ty const& _ty)
			: data{ &_ty }
			, size{ 1ull }
		{}

		batch(std::vector<_Ty> const& v)
			: data{ v.data() }
			, size{ v.size() }
		{}

		template <size_t _S>
		batch(std::array<_Ty, _S> const& a)
			: data{ a.data() }
			, size{ a.size() }
		{}

		_Ty const* begin() const { return data; }
		_Ty const* end() const { return data + size; }

		_Ty const& operator[](size_t n) const { return data[n]; }
	};
}