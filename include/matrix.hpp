#include <iostream>

class matrix_t {
private:
	float ** elements_;
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
	matrix_t operator -( matrix_t const & other ) const;
	matrix_t operator *( matrix_t const & other ) const;
	matrix_t add(matrix_t const & other) const {
		if (rows == other.rows && columns == other.columns) {
			for (unsigned int i = 0; i < rows; ++i) {
				for (unsigned int j = 0; j < columns; ++j) {
					other.data[i][j] = data[i][j] + other.data[i][j];
				}
			}
		}
		else {
			cout << "Something went wrong :(";
		}
		return other;
	}

	matrix_t & operator -=( matrix_t const & other );
	matrix_t & operator +=( matrix_t const & other );
	matrix_t & operator *=( matrix_t const & other );

	std::istream & read( std::istream & stream );
	std::ostream & write( std::ostream  & stream ) const;
};
