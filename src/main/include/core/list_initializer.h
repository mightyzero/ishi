#ifndef CORE_LISTINITIALIZER_H
#define CORE_LISTINITIALIZER_H

template<typename HostT, typename ElemT, unsigned int length = 0>
class ListInitializer {
public:
	typedef HostT Host;
	typedef ElemT Elem;
	
private:
	const Host& host;
	Elem        val;

	// Disable default constructor
	ListInitializer();

public:
	ListInitializer(Host& array, Elem& arg) : host(array), val(arg) {
		// intentially empty
	}

	ListInitializer<Host,Elem,length+1> operator,(Elem arg)	{
		return ListInitializer<Host,Elem,length+1>(arg);
	}

	~ListInitializer() {
		host[length] = val;
	}
};

#endif  // CORE_LISTINITIALIZER_H