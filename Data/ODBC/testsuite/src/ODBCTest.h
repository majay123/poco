//
// ODBCTest.h
//
// $Id: //poco/Main/Data/ODBC/testsuite/src/ODBCTest.h#4 $
//
// Definition of the ODBCTest class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef ODBCTest_INCLUDED
#define ODBCTest_INCLUDED


#include "Poco/Data/ODBC/ODBC.h"
#include "CppUnit/TestCase.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/ODBC/Utility.h"
#include "Poco/SharedPtr.h"
#include "Poco/Exception.h"
#include "SQLExecutor.h"


#define POCO_ODBC_TEST_DATABASE_SERVER "localhost"


class ODBCTest: public CppUnit::TestCase
{
public:
	typedef Poco::SharedPtr<Poco::Data::Session> SessionPtr;
	typedef Poco::SharedPtr<SQLExecutor>         ExecPtr;

	ODBCTest(const std::string& name,
		SessionPtr pSession,
		ExecPtr    pExecutor,
		std::string& rDSN,
		std::string& rUID,
		std::string& rPwd,
		std::string& rConnectString);

	~ODBCTest();

	virtual void setUp();
	virtual void tearDown();

	virtual void testBareboneODBC() = 0;

	virtual void testSimpleAccess();
	virtual void testComplexType();

	virtual void testSimpleAccessVector();
	virtual void testComplexTypeVector();
	virtual void testSharedPtrComplexTypeVector();
	virtual void testAutoPtrComplexTypeVector();
	virtual void testInsertVector();
	virtual void testInsertEmptyVector();

	virtual void testSimpleAccessList();
	virtual void testComplexTypeList();
	virtual void testInsertList();
	virtual void testInsertEmptyList();

	virtual void testSimpleAccessDeque();
	virtual void testComplexTypeDeque();
	virtual void testInsertDeque();
	virtual void testInsertEmptyDeque();

	virtual void testAffectedRows();

	virtual void testInsertSingleBulk();
	virtual void testInsertSingleBulkVec();

	virtual void testLimit();
	virtual void testLimitOnce();
	virtual void testLimitPrepare();
	virtual void testLimitZero();
	virtual void testPrepare();
	virtual void testBulk();
	virtual void testBulkPerformance();

	virtual void testSetSimple();
	virtual void testSetComplex();
	virtual void testSetComplexUnique();
	virtual void testMultiSetSimple();
	virtual void testMultiSetComplex();
	virtual void testMapComplex();
	virtual void testMapComplexUnique();
	virtual void testMultiMapComplex();
	virtual void testSelectIntoSingle();
	virtual void testSelectIntoSingleStep();
	virtual void testSelectIntoSingleFail();
	virtual void testLowerLimitOk();
	virtual void testLowerLimitFail();
	virtual void testCombinedLimits();
	virtual void testCombinedIllegalLimits();
	virtual void testRange();
	virtual void testIllegalRange();
	virtual void testSingleSelect();
	virtual void testEmptyDB();

	virtual void testBLOB();
	virtual void testBLOBContainer();
	virtual void testBLOBStmt();

	virtual void testDateTime();
	virtual void testDate();
	virtual void testTime();

	virtual void testFloat();
	virtual void testDouble();

	virtual void testTuple();
	virtual void testTupleVector();

	virtual void testInternalExtraction();
	virtual void testFilter();
	virtual void testInternalBulkExtraction();
	virtual void testInternalStorageType();

	virtual void testStoredProcedure();
	virtual void testStoredProcedureAny();
	virtual void testStoredProcedureDynamicAny();

	virtual void testStoredFunction();
	virtual void testStoredFunctionAny();
	virtual void testStoredFunctionDynamicAny();

	virtual void testNull();
	virtual void testRowIterator();
	virtual void testStdVectorBool();

	virtual void testAsync();

	virtual void testAny();
	virtual void testDynamicAny();

	virtual void testMultipleResults();

	virtual void testSQLChannel();

	virtual void testSQLLogger();

protected:
	typedef Poco::Data::ODBC::Utility::DriverMap Drivers;

	virtual void dropObject(const std::string& type, const std::string& name);
	virtual void recreatePersonTable();
	virtual void recreatePersonBLOBTable();
	virtual void recreatePersonDateTimeTable();
	virtual void recreatePersonDateTable();
	virtual void recreatePersonTimeTable();
	virtual void recreateStringsTable();
	virtual void recreateIntsTable();
	virtual void recreateFloatsTable();
	virtual void recreateTuplesTable();
	virtual void recreateVectorsTable();
	virtual void recreateAnysTable();
	virtual void recreateNullsTable(const std::string& notNull="");
	virtual void recreateBoolTable();
	virtual void recreateMiscTable();
	virtual void recreateLogTable();

	static SessionPtr init(const std::string& driver,
		std::string& dsn,
		std::string& uid,
		std::string& pwd,
		std::string& dbConnString,
		const std::string& db = "");

	static bool canConnect(const std::string& driver,
		std::string& dsn,
		std::string& uid,
		std::string& pwd,
		std::string& dbConnString,
		const std::string& db = "");

	bool bindValue(int i);

	Poco::Data::Session& session();
	SQLExecutor& executor();

	const std::string& dsn();
	const std::string& uid();
	const std::string& pwd();
	const std::string& dbConnString();

private:
	static Drivers    _drivers;
	static const bool _bindValues[8];
	SessionPtr        _pSession;
	ExecPtr           _pExecutor;
	std::string&      _rDSN;
	std::string&      _rUID;
	std::string&      _rPwd;
	std::string&      _rConnectString;
};


//
// inlines
//

inline void ODBCTest::testStoredProcedure() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredProcedure()");
}


inline void ODBCTest::testStoredProcedureAny() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredProcedureAny()");
}


inline void ODBCTest::testStoredProcedureDynamicAny() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredProcedureDynamicAny()");
}


inline void ODBCTest::testStoredFunction() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunction()");
}


inline void ODBCTest::testStoredFunctionAny() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionAny()");
}


inline void ODBCTest::testStoredFunctionDynamicAny() 
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::dropObject(const std::string& type, const std::string& name)
{
	throw Poco::NotImplementedException("ODBCTest::dropObject()");
}


inline void ODBCTest::recreatePersonTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::recreatePersonBLOBTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::recreatePersonDateTimeTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::recreatePersonDateTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::recreatePersonTimeTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::testStoredFunctionDynamicAny()");
}


inline void ODBCTest::recreateStringsTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateStringsTable()");
}


inline void ODBCTest::recreateIntsTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateIntsTable()");
}


inline void ODBCTest::recreateFloatsTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateFloatsTable()");
}


inline void ODBCTest::recreateTuplesTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateTuplesTable()");
}


inline void ODBCTest::recreateVectorsTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateVectorsTable()");
}


inline void ODBCTest::recreateAnysTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateAnysTable()");
}


inline void ODBCTest::recreateNullsTable(const std::string&)
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateNullsTable()");
}


inline void ODBCTest::recreateBoolTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateBoolTable()");
}


inline void ODBCTest::recreateMiscTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateMiscTable()");
}


inline void ODBCTest::recreateLogTable()
{ 
	throw Poco::NotImplementedException("ODBCTest::recreateLogTable()");
}


inline bool ODBCTest::bindValue(int i) 
{ 
	poco_assert (i < 8);
	return _bindValues[i]; 
}


inline Poco::Data::Session& ODBCTest::session() 
{ 
	poco_check_ptr (_pSession);
	return *_pSession; 
}


inline SQLExecutor& ODBCTest::executor() 
{ 
	poco_check_ptr (_pExecutor);
	return *_pExecutor; 
}


inline const std::string& ODBCTest::dsn() 
{ 
	return _rDSN; 
}


inline const std::string& ODBCTest::uid() 
{ 
	return _rUID; 
}


inline const std::string& ODBCTest::pwd() 
{ 
	return _rPwd; 
}


inline const std::string& ODBCTest::dbConnString() 
{ 
	return _rConnectString; 
}


#endif // ODBCTest_INCLUDED
