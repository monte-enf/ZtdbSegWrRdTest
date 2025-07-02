// ZtdbSegWrRdTest.cpp : Writes then reads a segment file.

#include <iostream>

#include "../Zappa/ZtdbSegWr.h"
#include "../Zappa/ZtdbSegRd.h"


int main ( )
{
	cout << "ZtdbSegWrRdTest: top\n\n";

	ZtdbSegWr segWr ( "segWrTest.bin" );

	segWr.add ( ZtdbSeg ( 0x100, 0x123 ) );

	vector < ZtdbSeg > segs;
	cout << "\n\nZtdbSegWrRdTest: Test.1\n";
	ZtdbSegRd::read ( "segWrTest.bin", segs );
	ZtdbSegRd::dump ( "ZtdbSegWrRdTest.1:", 0, segs );

	segWr.add ( ZtdbSeg ( 0x1000, 0x200 ) );
	segWr.add ( ZtdbSeg ( 0x2000, 0x300 ) );
	segWr.add ( ZtdbSeg ( 0x2001, 0x3301 ) );
	cout << "\n\nZtdbSegWrRdTest: Test.2\n";
	ZtdbSegRd::read ( "segWrTest.bin", segs );
	ZtdbSegRd::dump ( "ZtdbSegWrRdTest.2:", 3, segs );

	segWr.add ( ZtdbSeg ( 0x4000, 0x100000000 ) );
	segWr.add ( ZtdbSeg ( 0x8000, 0x200000000 ) );
	segWr.add ( ZtdbSeg ( 0x100008000, 0x200000001 ) );
	segWr.add ( ZtdbSeg ( 0x200008000, 0x200000002 ) );
	cout << "\n\nZtdbSegWrRdTest: Test.3\n";
	ZtdbSegRd::read ( "segWrTest.bin", segs );
	ZtdbSegRd::dump ( "ZtdbSegWrRdTest.3:", 6, segs );

	cout << "\n\nZtdbSegWrRdTest: done\n\n";

}