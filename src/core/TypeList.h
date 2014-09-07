#ifndef TYPELIST_H
#define TYPELIST_H

template<typename HeadT, typename TailT>
class TypeList
{
	typedef HeadT Head;
	typedef TailT Tail;
};

#endif  // TYPELIST_H