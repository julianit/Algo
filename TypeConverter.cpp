/*
	A discussion in Linked force me to develop this class
	in order to represent a nice solution that depends on the 
	return type only!!!
	Many proposals were given with templates 
	and 'auto', but they are overkill.
	
	So this class shows how we can use a class that looks like a function
	and calls the correct method depending on the lvalue.
	If no approporiate method is introduced the compiler report an error.
	
*/
class Converter
{
public:
	Converter(const char *nptr, char **endptr, int base)
	{
		m_nptr = nptr;
		m_endptr = endptr;
		m_base = base;
	}

	operator long long()
	{
		return strtoull(m_nptr, m_endptr, m_base);
	}

	operator unsigned long()
	{
		return strtoul(m_nptr, m_endptr, m_base);;
	}
protected:	
	//This members should be references or pointers
	// but for the sake of example this is not important.
	const char *m_nptr;
	char ** m_endptr;
	int m_base;
};

int main(void)
{
	const char *nptr = "123";
	char *endptr = "123";
	int base = 10;
	
	//Here is the interesting part 
	//1. Calls ctr
	//2. Calls 'operator long long' because of the lvalue
	long long ll = Converter(nptr, &endptr, base);
	
	//1. Calls ctr
	//2. Calls 'operator unsigned long' because of the lvalue
	unsigned long l = Converter(nptr, &endptr, base);
	
	//int i =  Converter(nptr, &endptr, base); //Not allowed: compiler report error
}