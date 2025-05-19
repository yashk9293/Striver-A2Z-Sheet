// Question Link :- https://leetcode.com/problems/reverse-words-in-a-string
// Reverse Words in a String


// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;

        vector<string> words;
        while(ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size()-1) {
                result += " ";
            }
        }
        return result;
    }
};


// OR
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        
        string result = "";
        while(ss >> word) {
            result = word + " " + result;
        }
        return result.substr(0, result.length()-1);
    }
};

/*
Iteration	word	result (before update)	 Updated result
1st	        "the"	    ""	                     "the "
2nd	        "sky"	    "the "	                 "sky the "
3rd	        "is"	    "sky the "	             "is sky the "
4th	        "blue"	    "is sky the "	         "blue is sky the "
*/



// Follow up: Could you solve it in-place with O(1) extra space?

// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());   // reverse whole string

        int l = 0, r = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            // if s[i] == ' ', further kuch nhi hoga, simply i inc hogke next iteration jayega
            while(i < n && s[i] != ' ') { // i ko agar char dikha to r ko dega and i++ and r++
                s[r] = s[i];
                i++;
                r++;
            }
            if(l < r) {
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
        }
        s = s.substr(0 , r-1);
        return s;
    }
};