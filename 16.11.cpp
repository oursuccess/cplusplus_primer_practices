
//front declare of ListItem
template<typename elemType> class ListItem;


template<typename elemType> class List{
	public:
		//we could just use the template with out <elemType> in field
		List<elemType>();
		List<elemType>(const List<elemType> &);
		List<elemType>& operator=(const List<elemType> &);
		~List();

		void insert(ListItem *ptr, elemType value);

	private:
		//this should be ListItem<elemType> *front, *end?
		ListItem *front, *end;
};
