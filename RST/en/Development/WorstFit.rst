.. This file is part of the OpenDSA eTextbook project. See
.. http://algoviz.org/OpenDSA for more details.
.. Copyright (c) 2012-2013 by the OpenDSA Project Contributors, and
.. distributed under an MIT open source license.

.. avmetadata::
   :author: Cliff Shaffer
   :prerequisites: 
   :topic: Memory Management

Worst Fit
=========

A strategy contrary to best fit might make sense because it tends to
minimize the effects of external fragmentation.
This is called :term:`worst fit`, which always allocates the largest
block on the list hoping that the remainder of the block will be
useful for servicing a future request.
In our example, the worst fit is the block of size 45, leaving a
remainder of size 15.
If there are a few unusually large requests, this approach
will have less chance of servicing them.
If requests generally tend to be of the same size, then this might be
an effective strategy.
Like best fit, worst fit requires searching the entire freelist at
each memory request to find the largest block.
Alternatively, the freelist can be ordered from largest to smallest
free block, possibly by using a priority queue implementation.

.. raw:: html

   <center> 
   <iframe id="FirstFit_iframe" 
        src="http://research.cs.vt.edu/AVresearch/MMtutorial/WorstFit.html"
        width="1000" height="600"
        frameborder="1" marginwidth="0" marginheight="0"
	scrolling="no">
   </iframe>
   </center>
