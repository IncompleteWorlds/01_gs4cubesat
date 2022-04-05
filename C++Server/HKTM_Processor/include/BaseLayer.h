/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */

#ifndef __BASE_HANDLER_H__
#define __BASE_HANDLER_H__

#include <string>
#include <memory>

using namespace std;

#include "AvroTypes.h"
#include "CommonTypes.h"

#include "DynamicFrame.h"

/*
The primitives that are exchanged between the data-link layer and adjacent layers are of the following four
types:
a) REQUEST primitive type: used by a higher layer to request a service from the next lower layer;
b) INDICATION primitive type: used by a layer to provide a service to notify the next higher layer of any
specific activity that is service related. The INDICATION primitive may be the result of an activity of the
lower layer related to the primitive type REQUEST at the peer entity;
c) RESPONSE primitive type: used by a layer to acknowledge receipt from a lower layer of the primitive
type INDICATION. AX.25 does not use the RESPONSE primitive; and
d) CONFIRM primitive type: used by a layer to provide the requested service to confirm that the activity has
been completed.

Figure 2.4 illustrates the use of the four primitive types in conjunction with the connect primitive.
Station A          DLSAP       DLSAP    Station B
DL-CONNECT Request   >>
                                >>      DL-CONNECT Indication
                                <<      DL-CONNECT Response
DL-CONNECT Confirm   <<

Figure 2.4. Example use of primitive types.
*/

class BaseLayer
{
public:
    BaseLayer()
        : dataGroupIndex_{ 0 }, dataFieldIndex_{ 0 }, parameters_{}, frames_{}
    {
    }

    virtual ~BaseLayer()
    {
    }

    // Operations
    // It receives a stream of bytes from bottom layer,
    // process it and pass to the upper layer
    //    a) REQUEST primitive type: used by a higher layer to request a service from the next lower layer;
    virtual RawFrameType request(RawFrameType& inRawData) = 0;

    //    b) INDICATION primitive type: used by a layer to provide a service to notify the next higher layer of any
    //    specific activity that is service related. The INDICATION primitive may be the result of an activity of the
    //    lower layer related to the primitive type REQUEST at the peer entity;
    virtual IW::ProcessedFrame indication(RawFrameType& inRawData) = 0;

    // It receives a stream of bytes from upper layer,
    // process it and pass to the bottom layer
    //    c) RESPONSE primitive type: used by a layer to acknowledge receipt from a lower layer of the primitive
    //    type INDICATION. AX.25 does not use the RESPONSE primitive; and
    virtual RawFrameType response(RawFrameType& inRawData) = 0;

    //    d) CONFIRM primitive type: used by a layer to provide the requested service to confirm that the activity has
    //    been completed.
    virtual IW::ProcessedFrame confirm(RawFrameType& inRawData) = 0;

    uint getDataGroupIndex() 
    {
        return dataGroupIndex_;
    }
    
    // Return the index of the field that contents the payload data
    uint getDataFieldIndex()
    {
        return dataFieldIndex_;
    }

    void setParameters(IW::ListParameters& inListParameters)
    {
        parameters_ = inListParameters;
    }
    
    void setFrameTypes(IW::ListFrameTypes& inListFrameTypes);
    

protected:
    uint dataGroupIndex_;
    uint dataFieldIndex_;

    // Parameters used by the Layer
    IW::ListParameters  parameters_;
    
    vector<DynamicFrame>  frames_;
};

#endif // __BASE_HANDLER_H__





/*
 * 
 * COMPOSITE PATTERN

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


class Handler1: public Base
{
  public:
     / * virtual * /void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. Don't handle requests 3 times out of 4
            cout << "H1 passed " << i << "  ";
            Base::handle(i); // 3. Delegate to the base class
        }
        else
          cout << "H1 handled " << i << "  ";
    }
};

class Handler2: public Base
{
  public:
     / * virtual * /void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passed " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "H2 handled " << i << "  ";
    }
};

class Handler3: public Base
{
  public:
     / * virtual * /void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passed " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "H3 handled " << i << "  ";
    }
};

int main()
{
  srand(time(0));
  Handler1 root;
  Handler2 two;
  Handler3 thr;
  root.add(&two);
  root.add(&thr);
  thr.setNext(&root);
  for (int i = 1; i < 10; i++)
  {
    root.handle(i);
    cout << '\n';
  }
}


  */
