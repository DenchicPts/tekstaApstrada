#include "lib.h"

bool hasUniqueLetters(const string& word) {
	unordered_set<char> uniqueLetters;
	for (char letter : word) {
		if (uniqueLetters.count(letter) > 0) {
			return false;  // ������� ������������
		}
		uniqueLetters.insert(letter);
	}
	return true;  // ��� ������� ���������
}

vector<string> WordsWithUniqueLetters(const vector<pair<string, int>>& wordPairs) {
	// ����� ���� � ����������� ���������
	vector<string> result;
	for (const auto& wordPair : wordPairs) {
		const string& word = wordPair.first;
		if (hasUniqueLetters(word)) {
			result.push_back(word);
		}
	}
	return result;
}

int UniqueLetters(const map<string, int>& word_counts) {
	// ������� ���������� ����
	int unique_word_count = 0;
	for (const auto& pair : word_counts) {
		if (pair.second == 1) {
			++unique_word_count;
		}
	}
	return unique_word_count;
}

string longest_word(const map < string, int> word_counts) {
	// ����� ������ �������� �����
	string longest_word;
	for (const auto& pair : word_counts) {
		if (pair.first.length() > longest_word.length()) {
			longest_word = pair.first;
		}
	}
	return longest_word;
}

int main() {

	string punctuation = ",./\'\";:?&^*(){}[]$#@!<>-=+1234567890";

	string filename = "text.txt";
	ifstream file(filename);
	if (!file.is_open()) { // � ������ ���� ����� ����
		cout << "�� ������� ������� ����" << endl;
		return 0;
	}

	map<string, int> word_counts = wordCounter(file, punctuation); // ������ ���������� ����
	file.close();

	vector<pair<string, int>> word_freq(word_counts.begin(), word_counts.end()); // ������ ������, ����� ������������� �� ����������

	sort(word_freq.begin(), word_freq.end(), [](auto const& p1, auto const& p2) {
		return p1.second > p2.second; // ������ ������� �� �����������, ����� �������� ������ �������, �� � ���� ���� �� ��� ��� ��� �����. � ��� ���� ��������
		});// ���������� �� ������� ����

	vector<string> unique_words = WordsWithUniqueLetters(word_freq);

	std::sort(unique_words.begin(), unique_words.end(), [](const string& a, const string& b) {
		return a.size() > b.size();// ���������� �� �� ������ �������� ���������� �������
	});
		// ����� �����������
	cout << "Total words: " << word_counts.size() << endl;
	cout << "Unique words: " << UniqueLetters(word_counts) << endl;
	cout << "Longest word: " << longest_word(word_counts) << endl;
	cout << "Most common word: ";
	for (int i = 0; i < 5; i++)
	{
		cout << word_freq[i].first << " : " << word_freq[i].second << "  ";
	}
	cout << endl;
	// ����� 5 ���� � ����������� �������
	cout << "Words with all unique letters: ";
	for (auto i = 0; i < 5; i++) {
		cout << unique_words[i] << " ";
	}
	cout << endl;
	return 0;
}

map<string, int> wordCounter(ifstream& file, string& punctuation)
{
	map<string, int> word_counts;
	string word;
	while (file >> word) {
		// ���������� �����, ������ 4 ��������
		if (word.length() < 4) {
			continue;
		} // ������� ������ ��� ����� �� ����� ������� �������� ��� ����� ������� ����� �������������� � ������
		// ������� ����� ���������� �� �����
		for (char const& c : punctuation) {
			word.erase(remove(word.begin(), word.end(), c), word.end());
			// ������� ������ c �� ������ word � ������� ������� remove
			// � ����� ������� �������, ������� ���� ���������� � ����� ���������, � ������� ������ erase
		}
		// ����������� ������� ��� ������� �����
		++word_counts[word];
	}
	return word_counts;
}

bool hasRepeatingLetters(const string& word) {
	map<char, int> letter_counts;
	for (char c : word) {
		if (isalpha(c)) {
			if (letter_counts[c] > 0) {
				return true;  // ���� ������������� �����
			}
			letter_counts[c]++;
		}
	}
	return false;  // ��� ������������� ����
}