#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	// Length
	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	// Count Words
	static short CountWords(string S1)
	{
		string delim = " ";
		short pos = 0, Counter = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
				Counter++;
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			Counter++;
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	// Upper First Letter Of Each Word
	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = toupper(S1[i]);
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	// Lower First Letter Of Each Word
	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = tolower(S1[i]);
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	// Upper All String
	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = toupper(S1[i]);
		return S1;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	// Lower All String
	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = tolower(S1[i]);
		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	// Invert Letter Case
	static char InvertLetterCase(char char1)
	{
		return (isupper(char1) ? tolower(char1) : toupper(char1));
	}

	// Invert All Letters Case
	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	// Count Letter;
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatCount = enWhatToCount::All)
	{
		if (WhatCount == enWhatToCount::All)
			return S1.length();
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;
			if (WhatCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}
	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	// Count Specific Letter
	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
				if (islower(S1[i]) == islower(Letter))
					Counter++;
		}
		return Counter;
	}

	// Is Vowel
	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o')
			|| (Ch1 == 'u'));
	}

	// Count Vowels

	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
			if (IsVowel(S1[i]))
				Counter++;
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	// Split
	static vector <string> Split(string S1, string Delim)
	{
		vector <string> vString;
		short pos = 0;
		string word = "";
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			word = S1.substr(0, pos);
			//if (word != "")
			vString.push_back(word);
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
			vString.push_back(S1);
		return vString;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	// Trim Left
	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
				return S1.substr(i, S1.length() - i);
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	// Trim Right
	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i > 0; i--)
		{
			if (S1[i] != ' ')
				return S1.substr(0, i + 1);
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	// Trim
	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	// Join String
	/* Using Vector Of Strings */
	static string JoinString(vector<string> vString, string Delim)
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 += (s + Delim);
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	/* Using Array Of Strings */
	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";
		for (short i = 0; i < Length; i++)
		{
			S1 += (arrString[i] + Delim);
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	// Reverse Words In String
	static string ReverseWordsInString(string S1)
	{
		vector <string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter = " ";
		}
		S2 = S2.substr(0, (S2.length() - 1)); // remove last space.
		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	// Replace Word
	static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		vector <string> vString = Split(S1, " ");
		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
					s = sReplaceTo;
			}
			else
				if (LowerAllString(s) == LowerAllString(StringToReplace))
					s = sReplaceTo;

		}
		return (JoinString(vString, " "));
	}
	string ReplaceWord(string StringToReplace, string sReplaceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sReplaceTo);
	}

	// Remove Punctuations
	static string RemovePunctuations(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}
		return S2;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};


