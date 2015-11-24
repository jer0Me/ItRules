#include <boost/variant/variant.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include "AbstractFrame.h"

namespace ItRules
{
	typedef boost::variant<int, std::string, AbstractFrame*, boost::gregorian::date, double> type;
}

