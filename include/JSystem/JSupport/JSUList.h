#ifndef JSULIST_H
#define JSULIST_H

#include "symbol_defines.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JSUPtrLink;
class JSUPtrList;

template<typename T>
class JSUList;

extern "C"
{
    // JSUPtrLink
    JSUPtrLink* JSUPtrLink_ct( JSUPtrLink* JSUPtrLinkThis, void* object );         // Constructor
    JSUPtrLink* JSUPtrLink_dt( JSUPtrLink* JSUPtrLinkThis, int16_t freeThis );     // Destructor

    // JSUPtrList
    JSUPtrList* JSUPtrList_ct( JSUPtrList* JSUPtrListThis, bool init );            // Constructor
    JSUPtrList* JSUPtrList_dt( JSUPtrList* JSUPtrListThis, int16_t freeThis );     // Destructor

    void JSUPtrList_initiate( JSUPtrList* JSUPtrListThis );
    void JSUPtrList_setFirst( JSUPtrList* JSUPtrListThis, JSUPtrLink* first );
    bool JSUPtrList_append( JSUPtrList* JSUPtrListThis, JSUPtrLink* ptr );
    bool JSUPtrList_prepend( JSUPtrList* JSUPtrListThis, JSUPtrLink* ptr );
    bool JSUPtrList_insert( JSUPtrList* JSUPtrListThis, JSUPtrLink* before, JSUPtrLink* ptr );
    bool JSUPtrList_remove( JSUPtrList* JSUPtrListThis, JSUPtrLink* ptr );
    JSUPtrLink* JSUPtrList_getNthLink( const JSUPtrList* JSUPtrListThis, uint32_t i );
}

//
// Link
//

class JSUPtrLink
{
   public:
    JSUPtrLink( void* object ) { JSUPtrLink_ct( this, object ); }
    // ~JSUPtrLink();

    void* getObjectPtr() const { return mObject; }
    JSUPtrList* getList() const { return mList; }
    JSUPtrLink* getNext() const { return mNext; }
    JSUPtrLink* getPrev() const { return mPrev; }

   public:
    void* mObject;
    JSUPtrList* mList;
    JSUPtrLink* mPrev;
    JSUPtrLink* mNext;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JSUPtrLink ) == 0x10 );

template<typename T>
class JSULink: public JSUPtrLink
{
   public:
    JSULink( T* object ): JSUPtrLink( (void*) object ) {}

    T* getObject() const { return (T*) getObjectPtr(); }
    JSUList<T>* getSupervisor() const { return (JSUList<T>*) this->getList(); }
    JSULink<T>* getNext() const { return (JSULink<T>*) this->JSUPtrLink::getNext(); }
    JSULink<T>* getPrev() const { return (JSULink<T>*) this->JSUPtrLink::getPrev(); }
} __attribute__( ( __packed__ ) );

//
// List
//

class JSUPtrList
{
   public:
    JSUPtrList() { this->initiate(); }
    JSUPtrList( bool init ) { JSUPtrList_ct( this, init ); }
    // ~JSUPtrList();

    void initiate() { JSUPtrList_initiate( this ); }
    void setFirst( JSUPtrLink* first ) { JSUPtrList_setFirst( this, first ); }
    bool append( JSUPtrLink* ptr ) { return JSUPtrList_append( this, ptr ); }
    bool prepend( JSUPtrLink* ptr ) { return JSUPtrList_prepend( this, ptr ); }
    bool insert( JSUPtrLink* before, JSUPtrLink* ptr ) { return JSUPtrList_insert( this, before, ptr ); }
    bool remove( JSUPtrLink* ptr ) { return JSUPtrList_remove( this, ptr ); }
    JSUPtrLink* getNthLink( uint32_t i ) const { return JSUPtrList_getNthLink( this, i ); }

    JSUPtrLink* getFirstLink() const { return mHead; }
    JSUPtrLink* getLastLink() const { return mTail; }
    uint32_t getNumLinks() const { return mLength; }

   private:
    JSUPtrLink* mHead;
    JSUPtrLink* mTail;
    uint32_t mLength;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JSUPtrList ) == 0xC );

template<typename T>
class JSUList: public JSUPtrList
{
   public:
    JSUList(): JSUPtrList() {}
    JSUList( bool init ): JSUPtrList( init ) {}

    // ~JSUList() {}

    bool append( JSULink<T>* link ) { return this->JSUPtrList::append( (JSUPtrLink*) link ); }

    bool prepend( JSULink<T>* link ) { return this->JSUPtrList::prepend( (JSUPtrLink*) link ); }

    bool insert( JSULink<T>* before, JSULink<T>* link )
    {
        return this->JSUPtrList::insert( (JSUPtrLink*) before, (JSUPtrLink*) link );
    }

    bool remove( JSULink<T>* link ) { return this->JSUPtrList::remove( (JSUPtrLink*) link ); }

    JSULink<T>* getFirst() const { return (JSULink<T>*) getFirstLink(); }

    JSULink<T>* getLast() const { return (JSULink<T>*) getLastLink(); }

    JSULink<T>* getEnd() const { return nullptr; }

    uint32_t getNumLinks() const { return this->JSUPtrList::getNumLinks(); }
} __attribute__( ( __packed__ ) );

template<typename T>
class JSUListIterator
{
   public:
    JSUListIterator(): mLink( nullptr ) {}
    JSUListIterator( JSULink<T>* link ): mLink( link ) {}
    JSUListIterator( JSUList<T>* list ): mLink( list->getFirst() ) {}

    JSUListIterator<T>& operator=( JSULink<T>* link )
    {
        this->mLink = link;
        return *this;
    }

    T* getObject() { return this->mLink->getObject(); }

    bool operator==( JSULink<T> const* other ) const { return this->mLink == other; }
    bool operator!=( JSULink<T> const* other ) const { return this->mLink != other; }
    bool operator==( JSUListIterator<T> const& other ) const { return this->mLink == other.mLink; }
    bool operator!=( JSUListIterator<T> const& other ) const { return this->mLink != other.mLink; }

    JSUListIterator<T> operator++( int )
    {
        JSUListIterator<T> prev = *this;
        this->mLink = this->mLink->getNext();
        return prev;
    }

    JSUListIterator<T>& operator++()
    {
        this->mLink = this->mLink->getNext();
        return *this;
    }

    JSUListIterator<T> operator--( int )
    {
        JSUListIterator<T> prev = *this;
        this->mLink = this->mLink->getPrev();
        return prev;
    }

    JSUListIterator<T>& operator--()
    {
        this->mLink = this->mLink->getPrev();
        return *this;
    }

    T& operator*() { return *this->getObject(); }

    T* operator->() { return this->getObject(); }

   private:
    JSULink<T>* mLink;
} __attribute__( ( __packed__ ) );

//
// Tree
//

template<typename T>
class JSUTree: public JSUList<T>, public JSULink<T>
{
   public:
    JSUTree( T* owner ): JSUList<T>(), JSULink<T>( owner ) {}
    // ~JSUTree() {}

    bool appendChild( JSUTree<T>* child ) { return this->append( child ); }

    bool removeChild( JSUTree<T>* child ) { return this->remove( child ); }

    bool insertChild( JSUTree<T>* before, JSUTree<T>* child ) { return this->insert( before, child ); }

    JSUTree<T>* getEndChild() const { return nullptr; }

    JSUTree<T>* getFirstChild() const { return (JSUTree<T>*) this->getFirst(); }

    JSUTree<T>* getLastChild() const { return (JSUTree<T>*) this->getLast(); }

    JSUTree<T>* getNextChild() const { return (JSUTree<T>*) this->getNext(); }

    JSUTree<T>* getPrevChild() const { return (JSUTree<T>*) this->getPrev(); }

    uint32_t getNumChildren() const { return this->getNumLinks(); }

    T* getObject() const { return (T*) this->getObjectPtr(); }

    JSUTree<T>* getParent() const { return (JSUTree<T>*) this->getList(); }
} __attribute__( ( __packed__ ) );

template<typename T>
class JSUTreeIterator
{
   public:
    JSUTreeIterator(): mTree( nullptr ) {}
    JSUTreeIterator( JSUTree<T>* tree ): mTree( tree ) {}

    JSUTreeIterator<T>& operator=( JSUTree<T>* tree )
    {
        this->mTree = tree;
        return *this;
    }

    T* getObject() { return this->mTree->getObject(); }

    bool operator==( JSUTree<T>* other ) { return this->mTree == other; }

    bool operator!=( JSUTree<T>* other ) { return this->mTree != other; }

    JSUTreeIterator<T> operator++( int )
    {
        JSUTreeIterator<T> prev = *this;
        this->mTree = this->mTree->getNextChild();
        return prev;
    }

    JSUTreeIterator<T>& operator++()
    {
        this->mTree = this->mTree->getNextChild();
        return *this;
    }

    T& operator*() { return *this->getObject(); }

    T* operator->() { return this->getObject(); }

   private:
    JSUTree<T>* mTree;
} __attribute__( ( __packed__ ) );

#endif