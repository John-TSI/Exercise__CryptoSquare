#include<iostream>
#include<algorithm>
#include"../inc/cipher.hpp"


_CS::Cipher::Cipher(string& input) : message(input) {}
_CS::Cipher::Cipher(const string& input) : message(input) {}


void _CS::Cipher::NormaliseInput()
{
    string tmp{message};
    tmp.erase
    (
        std::remove_if( tmp.begin(), tmp.end(), [](const char& c){ return !isalnum(c); } )
        , tmp.end() 
    );
    std::transform
    (
        tmp.begin(), tmp.end(), 
        tmp.begin(), [](const char& c){ return tolower(c); }
    );
    message = std::move(tmp);
}


void _CS::Cipher::ComputeCipherDimensions()
{
    while( cols*cols < message.length() ){ ++cols; }
    rows = ( cols*cols == message.length() ) ? cols : cols - 1;
}


void _CS::Cipher::FragmentMessage()
{
    for(int r{0}; r < rows; ++r)
    {
        fragments.push_back(message.substr(r*cols, cols));
    }
}


void _CS::Cipher::EncodeMessage()
{
    for(int c{0}; c < cols; ++c)
    {
        for(int r{0}; r < rows; ++r)
        {   
            (c <= fragments[r].length() - 1)
            ? encodedMessage.append( string(1, fragments[r][c]) )
            : encodedMessage.append(" ");

            if(r == rows-1){ encodedMessage.append(" "); }
        }
    }
}


void _CS::Cipher::Encode()
{
    NormaliseInput();
    ComputeCipherDimensions();
    FragmentMessage();
    EncodeMessage();
    std::cout << encodedMessage << '\n';
}