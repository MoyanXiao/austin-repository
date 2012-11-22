#define BOOST_TEST_MODULE master_test_suite_name
#define	BOOST_TEST_DYN_LINK			[>  <]
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_name)

BOOST_AUTO_TEST_CASE(test_case_name) {
	BOOST_MESSAGE( "Boost UTF Hello World" );
	BOOST_WARN(true);
}
BOOST_AUTO_TEST_SUITE_END()

