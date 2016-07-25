
/*
 * This file was automatically generated using swig_doc.py.
 *
 * Any changes to it will be lost next time it is regenerated.
 */




%feature("docstring") gr::lets_test_some_stuff::taggedAccessCode "<+description of block+>"

%feature("docstring") gr::lets_test_some_stuff::taggedAccessCode::make "Return a shared_ptr to a new instance of lets_test_some_stuff::taggedAccessCode.

To avoid accidental use of raw pointers, lets_test_some_stuff::taggedAccessCode's constructor is in a private implementation class. lets_test_some_stuff::taggedAccessCode::make is the public interface for creating new instances.

Params: (NONE)"

%feature("docstring") gr::lets_test_some_stuff::taggedFileSource "Read stream from file."

%feature("docstring") gr::lets_test_some_stuff::taggedFileSource::make "Create a file source.

Opens  as a source of items into a flowgraph. The data is expected to be in binary format, item after item. The  of the block determines the conversion from bits to items.

If  is turned on, the file will repeat the file after it's reached the end.

Params: (itemsize, filename, repeat, blockLength)"

%feature("docstring") gr::lets_test_some_stuff::taggedFileSource::seek "seek file to  relative to

Params: (seek_point, whence)"

%feature("docstring") gr::lets_test_some_stuff::taggedFileSource::open "Opens a new file.

Params: (filename, repeat)"

%feature("docstring") gr::lets_test_some_stuff::taggedFileSource::close "Close the file handle.

Params: (NONE)"

%feature("docstring") gr::lets_test_some_stuff::taggedHeader "<+description of block+>"

%feature("docstring") gr::lets_test_some_stuff::taggedHeader::make "Return a shared_ptr to a new instance of lets_test_some_stuff::taggedHeader.

To avoid accidental use of raw pointers, lets_test_some_stuff::taggedHeader's constructor is in a private implementation class. lets_test_some_stuff::taggedHeader::make is the public interface for creating new instances.

Params: (NONE)"

%feature("docstring") gr::lets_test_some_stuff::taggedPacketGate "<+description of block+>"

%feature("docstring") gr::lets_test_some_stuff::taggedPacketGate::make "Return a shared_ptr to a new instance of lets_test_some_stuff::taggedPacketGate.

To avoid accidental use of raw pointers, lets_test_some_stuff::taggedPacketGate's constructor is in a private implementation class. lets_test_some_stuff::taggedPacketGate::make is the public interface for creating new instances.

Params: (tagName)"