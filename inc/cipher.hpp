#ifndef CIPHER_HPP
#define CIPHER_HPP

#include<string>
#include<vector>


namespace _CS // CryptoSquare
{
    using std::string; using std::vector;

    class Cipher
    {
        string message{}, encodedMessage{};
        vector<string> fragments{};
        int rows{0}, cols{0};

        public:
            explicit Cipher(string&);
            explicit Cipher(const string&);

            void NormaliseInput();
            void ComputeCipherDimensions();
            void FragmentMessage();
            void EncodeMessage();

            void Encode();
    };
}

#endif // CIPHER_HPP