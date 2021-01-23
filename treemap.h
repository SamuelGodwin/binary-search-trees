#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;
    
    // code for KeyValuePair here
	KeyValuePair(const Key kIn, Value vIn)
	: k(kIn),
		v(vIn) {}
    
    KeyValuePair(const Key kIn)
	: k(kIn) {}
    
    bool operator< (const KeyValuePair & pairToCompare) const {
		return (k < pairToCompare.k);
	}

    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}




template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // code for TreeMap here
    
    
    KeyValuePair<Key, Value> * find(const Key & k) {
		return &(tree.find(KeyValuePair<Key,Value>(k))->data);
	}
    
};


// do not edit below this line

#endif
