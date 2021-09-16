/**
 * regex_match - match an string with a pattern
 *
 * @str: string to match
 * @pattern: regex pattern that needs to match
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 *
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
	{
		if (!*pattern)
			return (1);
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 2));
	}
	else if (*(pattern + 1) == '*')
	{
		if (*str == *pattern || *pattern == '.')
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	else if (*str == *pattern || *pattern == '.')
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
