/* *** ODSATag: Freelink *** */
static class Link {         // Singly linked list node with freelist support
  private Object e;  // Value for this node
  private Link n;    // Point to next node in list

  // Constructors
  Link(Object it, Link inn) { e = it; n = inn; }
  Link(Link inn) { e = null; n = inn; }

  Object element() { return e; }           // Return the value
  void setelement(Object it) { e = it; }   // Set element value
  Link next() { return n; }                // Return next link
  void setnext(Link inn) { n = inn; }      // Set next link

  // Extensions to support freelists
  static Link freelist = null;     // Freelist for the class

  // Return a new link, from freelist if possible
  static Link get(Object it, Link inn) {
    if (freelist == null)
      return new Link(it, inn);        // Get from "new"
    Link temp = freelist;              // Get from freelist
    freelist = freelist.next();
    temp.setelement(it);
    temp.setnext(inn);
    return temp;
  }

  // Return a link node to the freelist
  void release() {
    e = null;   // Drop reference to the element
    n = freelist;
    freelist = this;
  }
}
/* *** ODSAendTag: Freelink *** */
