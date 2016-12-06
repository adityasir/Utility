#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>


// Left-aligned, right-padded fixed-length char 
template <size_t N, char PAD = ' '>
struct LeftAlignedFixedLenChar {
	LeftAlignedFixedLenChar() {
		std::memset(m_data, PAD, N);
	}

	template <typename S>
	LeftAlignedFixedLenChar(const S& s) {
		set(s);
	}

	const char* buffer() const {
		return m_data;
	}

	auto length() const {  return m_lenght;}

	void set(const char* s) {
		unsigned i = 0;
		for (; i < N && '\0' != s[i]; ++i) {
			m_data[i] = s[i];
		}
                m_lenght = i;
		if (N > i) {
			std::memset(&m_data[i], PAD, N - i);
		}
	}

	void set(const char* s, size_t length) {
		unsigned i = 0;
		for (; i < N && i < length; ++i) {
			m_data[i] = s[i];
		}
		if (N > i) {
			std::memset(&m_data[i], PAD, N - i);
		}
                m_lenght = length;
	}

	template <size_t N2, char PAD2>
	void set(const LeftAlignedFixedLenChar<N2, PAD2>& s) {
		set(s.data(), s.length());
	}

private:
	char m_data[N];
        unsigned m_lenght = 0; 
};

using char10 = LeftAlignedFixedLenChar<10>;
int main() {
    const auto a = std::string("0120456789");      
    const auto s = char10(a.c_str());
   
    std::cout<<"Length = "<<s.length() <<"\t[";
    for( auto i = 0; i <s.length() ; ++i) {
        std::cout << (s.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    const auto temp = std::string("0 234");
    const auto b = char10(temp.c_str());
    std::cout<<"Length = "<<b.length() <<"\t[";
    for( auto i = 0; i < b.length() ; ++i) {
        std::cout<<(b.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    const auto c = char10(" 123456789");
    std::cout<<"Length = "<<c.length() <<"\t[";
    for( auto i = 0; i < c.length() ; ++i) {
        std::cout<<(c.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 
    
    const auto d = char10("012345678 ");
    std::cout<<"Length = "<<d.length() <<"\t[";
    for( auto i = 0; i < d.length() ; ++i) {
        std::cout<<(d.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    const auto e = char10("          ");
    std::cout<<"Length = "<<e.length() <<"\t[";
    for( auto i = 0; i < d.length() ; ++i) {
        std::cout<<(e.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    const auto f = char10(" ");
    std::cout<<"Length = "<<f.length() <<"\t[";
    for( auto i = 0; i < f.length() ; ++i) {
        std::cout<<(f.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    const auto g = char10("1234");
    std::cout<<"Length = "<<g.length() <<"\t[";
    for( auto i = 0; i < g.length() ; ++i) {
        std::cout<<(g.buffer())[i] ; 
    }
    std::cout<<"]"<<"\t["; 
    for( auto i = 0; i < 10 ; ++i) {
        std::cout<<(g.buffer())[i] ; 
    }
    std::cout<<"]"<<std::endl; 

    return 1;
}
