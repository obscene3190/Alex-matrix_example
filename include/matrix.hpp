#include <iostream>

template <typename T> class matrix_t {
private:
	T ** elements_;
	std::size_t rows_;
	std::size_t collumns_;
public:
	matrix_t();
	matrix_t( matrix_t const & other );
	matrix_t & operator =( matrix_t const & other );
	~matrix_t();

	std::size_t rows() const;
	std::size_t collumns() const;

	matrix_t operator +( matrix_t const & other ) const;
	checksum(matrix_t const & other) const;
	matrix_t operator -( matrix_t const & other ) const;
	checksub(matrix_t const & other) const;
	matrix_t operator *( matrix_t const & other ) const;
	checkmul(matrix_t const & other) const;
	matrix_t & operator +=( matrix_t const & other );
	checksumequal(matrix_t const & other) const;
	matrix_t & operator -=( matrix_t const & other );
	checksubequal(matrix_t const & other) const;
	matrix_t & operator *=( matrix_t const & other );
	checkmulequal(matrix_t const & other) const;

	std::istream & read( std::istream & stream );
	std::ostream & write( std::ostream  & stream ) const;
};
