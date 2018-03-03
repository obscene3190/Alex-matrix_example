#include "matrix.hpp"

matrix_t::matrix_t() : elements_{ nullptr }, rows_{ 0 }, collumns_{ 0 }
{
}

matrix_t::matrix_t(matrix_t const & other)
{
}

matrix_t & matrix_t::operator =(matrix_t const & other)
{
	if (this != &other) {
		for (unsigned int i = 0; i < rows_; ++i) {
			delete[] elements_[i];
		}
		delete[] elements_;
		rows_ = other.rows_;
		columns_ = other.columns_;
		elements_ = new int *[rows_];
		for (unsigned int i = 0; i < rows_; ++i) {
			elements_[i] = new int[columns_];
			for (unsigned int j = 0; j < columns_; ++j) {
				elements_[i][j] = matrix.elements_[i][j];
			}
		}
	}
	else {
		return *this;
	}
}

matrix_t::~matrix_t()
{
}

std::size_t matrix_t::rows() const
{
	return rows_;
}

std::size_t matrix_t::collumns() const
{
	return collumns_;
}

matrix_t matrix_t::operator +(matrix_t const & other) const
{
	matrix_t result;
	result.rows_ = rows_;
	result.columns_ = columns_;
	result.elements_ = new int *[rows_];
	if (rows_ == other.rows_ && columns_ == other.columns_) {
		for (unsigned int i = 0; i < rows_; ++i) {
			result.elements_[i] = new int[columns_];
			for (unsigned int j = 0; j < columns_; ++j) {
				result.elements_[i][j] = elements_[i][j] + other.elements_[i][j];
			}
		}
	}
	else {
		cout << "Something went wrong :(";
	}
	return result;
}

matrix_t matrix_t::operator -(matrix_t const & other) const
{
	matrix_t result;

	return result;
}

matrix_t matrix_t::operator *(matrix_t const & other) const
{
	matrix_t result;

	return result;
}

matrix_t & matrix_t::operator -=(matrix_t const & other)
{
	return *this;
}

matrix_t & matrix_t::operator +=(matrix_t const & other)
{
	return *this;
}

matrix_t & matrix_t::operator *=(matrix_t const & other)
{
	return *this;
}

std::istream & matrix_t::read(std::istream & stream)
{
	std::size_t rows;
	std::size_t collumns;
	char symbol;

	bool success = true;
	if (stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns) {
		float ** elements = new float *[rows];
		for (std::size_t i = 0; success && i < rows; ++i) {
			elements[i] = new float[collumns];
			for (std::size_t j = 0; j < collumns; ++j) {
				if (!(stream >> elements[i][j])) {
					success = false;
					break;
				}
			}
		}

		if (success) {
			for (std::size_t i = 0; i < rows_; ++i) {
				delete[] elements_[i];
			}
			delete[] elements_;

			rows_ = rows;
			collumns_ = collumns;
			elements_ = elements;
		}
		else {
			for (std::size_t i = 0; i < rows; ++i) {
				delete[] elements[i];
			}
			delete[] elements;
		}
	}
	else {
		success = false;
	}

	if (!success) {
		stream.setstate(std::ios_base::failbit);
	}

	return stream;
}

std::ostream & matrix_t::write(std::ostream & stream) const
{
	stream << rows_ << ", " << collumns_;
	for (std::size_t i = 0; i < rows_; ++i) {
		stream << '\n';
		for (std::size_t j = 0; j < collumns_; ++j) {
			stream << elements_[i][j];
			if (j != rows_ - 1) {
				stream << ' ';
			}
		}
	}

	return stream;
}
