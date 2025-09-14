/*966. Vowel Spellchecker

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
Example 2:

Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]*/
class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool check(vector<string>& wordlist, string query, string& match) {
        for (auto& word : wordlist) {
            if (word.size() != query.size())
                continue;
            bool ok = true;
            for (int i = 0; i < word.size(); i++) {
                char a = tolower(word[i]);
                char b = tolower(query[i]);
                if (a == b)
                    continue;
                if (!(isVowel(a) && isVowel(b))) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                match = word;
                return true;
            }
        }
        return false;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, unordered_set<string>> mpp;
        vector<string> ans;
        for (auto i : wordlist) {
            string temp = i;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            mp[temp].push_back(i);
            mpp[temp].insert(i);
        }
        for (auto i : queries) {
            string temp = i, x;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (mp.find(temp) != mp.end()) {
                unordered_set<string> st = mpp[temp];
                vector<string> t = mp[temp];
                if (st.find(i) != st.end())
                    ans.push_back(i);
                else {
                    ans.push_back(t[0]);
                }
            } else if (check(wordlist, temp, x)) {
                ans.push_back(x);
            } else
                ans.push_back("");
        }
        return ans;
    }
};
