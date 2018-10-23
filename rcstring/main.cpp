#include <cstddef>
#include <cassert>
#include <iostream>
#include <string.h>

/*
 * -------------------------------------------------------------------------------------------------
 * Put a ref count inside the String class to make this easy, like
 *     class String {
 *     private:
 *         std::size_t m_rc;
 *         ...
 *     }
 *
 * NOTE:
 * 1. You are not supposed to use c++ standard string i.e. std::string.
 * 2. Make sure your code should not have Memory errors and leaks.
 * -------------------------------------------------------------------------------------------------
 */


// Your implementation here ...

using namespace std;

class String {
	public:
		String(const char* s="") : str(strdup(s)), m_sz(strlen(s)) {
			this->m_rc = 1;
		}
		~String(){
			free(str);
		}
		String(String &s) : str(s.str), m_sz(s.m_sz) {
			
		}
		String &operator=(const String &s) {
			free(str);
			str = strdup(s.str);
			m_sz = s.m_sz;
		}
		String &operator=(const std::nullptr_t) {
			free(str);
			return NULL;
		}
		const char * &operator*() {
			return str;
		}
		ostream& operator<<(ostream &out, const String &s){
			out << s.str;
			return out;
		}
		int length() {
			return m_sz;
		}
		void clear() {
			free(str);
			str = "";
		}
		
	private:
		std::size_t m_rc;
		std::size_t m_sz;
		char* str;
};

typedef String* StringPtr;
int
main() {
    StringPtr sp1 = new String("hello");
    StringPtr sp2; // Points to nullptr.

    sp1 = sp1; // Self-assignment.
    sp2 = sp1;

    // The type of nullptr is std::nullptr_t, so you can overload on that;
    sp1 = nullptr;

    std::cout << *sp2 << std::endl;
    sp2 = nullptr;
    // String should be freed at this point.

    StringPtr sp3 = new String("goodbye");
    sp3->length();
    assert(sp3->length() == 7);
    std::cout << *sp3 << std::endl;

    sp3->clear(); // Makes it the empty string.
    assert(sp3->length() == 0);
    std::cout << *sp3 << std::endl;

    StringPtr sp4 = new String("one");
    StringPtr sp5 = new String(", ");
    StringPtr sp6 = new String("two");
    std::cout << (*sp4 + *sp5 + *sp6) << std::endl;
    
}




