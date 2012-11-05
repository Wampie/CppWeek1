/* 
 * File:   main.cpp
 * Author: Wampie
 *
 * Created on November 5, 2012, 5:37 AM
 */

#include <cstdlib>
#include<iostream.h>

#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */


int main() {

    string s;

    while (true) {
        getline(cin, s);
        double r = 0.0;
        int first = 1;

        if (s == "quit") {
            return 0;
        }
        if (s[0] == '+') {
            string h;
            double value = 0;
            for (std::string::size_type i = 2; i < s.size(); ++i) {
                if (i == s.size() -1) {
                    h += s.at(i);
                }
                if (s[i] == ' ' || i == s.size() -1 ) {
                    value = 0;
                    char* endptr;
                    value = strtod(h.c_str(), &endptr);
                    h = "";
                    if (r == 0.0 && first == 1) {
                        r = value;
                        first = 0;
                    } else {
                        r += value;
                    }
                } else {
                    h += s.at(i);
                }
            }
            cout<<r;
            cout<<"";
            r = 0;
            first = 1;
        }

        if (s[0] == '-') {
            string h;
            double value = 0;
            for (std::string::size_type i = 2; i < s.size(); ++i) {
                if (i == s.size() -1) {
                    h += s.at(i);
                }
                if (s[i] == ' ' || i == s.size() -1 ) {
                    value = 0;
                    char* endptr;
                    value = strtod(h.c_str(), &endptr);
                    h = "";
                    if (r == 0.0 && first == 1) {
                        r = value;
                        first = 0;
                    } else {
                        r = r - value;
                    }
                } else {
                    h += s.at(i);
                }
            }
            cout<<r;
            cout<<"";
            r = 0;
            first = 1;
        }

        if (s[0] == '*') {
            string h;
            double value = 0;
            for (std::string::size_type i = 2; i < s.size(); ++i) {
                if (i == s.size() -1) {
                    h += s.at(i);
                }
                if (s[i] == ' ' || i == s.size() -1 ) {
                    value = 0;
                    char* endptr;
                    value = strtod(h.c_str(), &endptr);
                    h = "";
                    if (r == 0.0 && first == 1) {
                        r = value;
                        first = 0;
                    } else {
                        r = r * value;
                    }
                } else {
                    h += s.at(i);
                }
            }
            cout<<r;
            cout<<"";
            r = 0;
            first = 1;
        }

        if (s[0] == '/') {
            string h;
            double value = 0;
            for (std::string::size_type i = 2; i < s.size(); ++i) {
                if (i == s.size() -1) {
                    h += s.at(i);
                }
                if (s[i] == ' ' || i == s.size() -1 ) {
                    value = 0;
                    char* endptr;
                    value = strtod(h.c_str(), &endptr);
                    h = "";
                    if (r == 0.0 && first == 1) {
                        r = value;
                        first = 0;
                    } else {
                        r = r / value;
                    }
                } else {
                    h += s.at(i);
                }
            }
            cout<<r;
            cout<<"";
            r = 0;
            first = 1;
        }

    }
}

typedef std::set<int>   Sieve;

int main()
{
    static int const max = 100;

    Sieve   sieve;

    for(int loop=2;loop < max;++loop)
    {
        sieve.insert(loop);
    }


    // A set is ordered.
    // So going from beginning to end will give all the values in order.
    for(Sieve::iterator loop = sieve.begin();loop != sieve.end();++loop)
    {
        // prime is the next item in the set
        // It has not been deleted so it must be prime.
        int             prime   = *loop;

        // deleter will iterate over all the items from
        // here to the end of the sieve and remove any
        // that are divisable be this prime.
        Sieve::iterator deleter = loop;
        ++deleter;

        while(deleter != sieve.end())
        {
            if (((*deleter) % prime) == 0)
            {
                // If it is exactly divasable then it is not a prime
                // So delete it from the sieve. Note the use of post
                // increment here. This increments deleter but returns
                // the old value to be used in the erase method.
                sieve.erase(deleter++);
            }
            else
            {
                // Otherwise just increment the deleter.
                ++deleter;
            }
        }
    }

    // This copies all the values left in the sieve to the output.
    // i.e. It prints all the primes.
    std::copy(sieve.begin(),sieve.end(),std::ostream_iterator<int>(std::cout,"\n"));

}

int main(int argc, char** argv) {
    cout << "Hello World!";
    return 0;
}

