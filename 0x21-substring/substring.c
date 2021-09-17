#include "substring.h"

/**
 * same_value - finds if array is composed only of ones
 * @array: array to check on
 * @nb_words: number of words
 *
 * Return: 1 if all elements are one 0 otherwise
 */
static int same_value(const int array[], int nb_words)
{
	int i = 0;

	for (i = 0; i < nb_words; i++)
	{
		if (array[i] != 1)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * find_substring - Finds all the possible substrings
 * @s: string to scan.
 * @words: array of words all substrings.
 * @nb_words: number of results in the array words.
 * @n: Holds the address at which to store the number of results.
 * Return: allocated array, storing each index in s, at which a substring
 *  was found. If no solution is found, NULL can be returned
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int str_len = 0, word_len = 0, word_count = 0, index = 0;
	int concat_len = 0, word_index = 0;
	int *results, *found;

	if (!s || !words || !(*words) || !nb_words)
		return (NULL);

	str_len = strlen(s);
	results = calloc(str_len, sizeof(int));
	found = calloc(nb_words, sizeof(int));
	if (!found || !results)
		return (NULL);

	*n = 0;
	word_len = strlen(words[0]);
	concat_len = nb_words * word_len;

	for (index = 0; index <= str_len - concat_len; index++)
	{
		memset(found, 0, nb_words * sizeof(int));
		for (word_count = 0; word_count < concat_len; word_count += word_len)
		{
			for (word_index = 0; word_index < nb_words; word_index++)
			{
				if (!found[word_index] &&
						strncmp(s + index + word_count, words[word_index], word_len) == 0)
				{
					found[word_index] = 1;
					break;
				}
			}
		}
		if (same_value(found, nb_words))
			results[(*n)++] = index;
	}
	free(found);
	return (results);
}
