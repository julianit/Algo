class Converter
{
public:
	const char *m_nptr;
	char ** m_endptr;
	int m_base;
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
}