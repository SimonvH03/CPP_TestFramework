#ifndef VALIDATIONTOOLS_HPP
# define VALIDATIONTOOLS_HPP
# include <stdexcept>
# include <source_location>
# include <sstream>

class	validationToolsException : public std::exception
{
	public:
		validationToolsException(
			std::string const &message = "No apparent reason...")
			:	_message(message) {}

		const char *what() const throw() override {
			return (_message.c_str());
		}

	private:
		std::string	_message;
};

inline void	check(
	std::string const &expression, bool result)
{
	if (!result) throw validationToolsException(
		"Check failed: (" + expression + ") is false");
}
# define CHECK(expr) check(#expr, (expr))

template <typename A, typename B>
void	equate(
	std::string	const &aStr,
	std::string const &bStr,
	A const &a,
	B const &b)
{
	if (a != b) throw validationToolsException(
		"Equation failed: " + aStr + " != " + bStr);
}
# define EQUATE(a, b) equate(#a, #b, a, b)

#endif
