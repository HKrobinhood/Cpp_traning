#ifndef __ENTITY_H__
#define __ENTITY_H__



class entity {
    public:
        const int x; 
        int& ref;  
        entity(int val, int& r) : x(val), ref(r) {}  
};

#endif

