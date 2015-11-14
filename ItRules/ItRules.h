#include <boost/variant/variant.hpp>
#include "AbstractFrame.h"
#include <boost/date_time/gregorian/greg_date.hpp>

namespace ItRules
{
	typedef boost::variant<int, std::string, double, AbstractFrame*, boost::gregorian::date> type;
}
