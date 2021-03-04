#ifndef GLOBAL_H
#define GLOBAL_H
//
#include <qstring.h>
//


class Global{
public:
	static Global *Instance();
	void SetMajor(const QString &major){ mMajor = major; }
	const QString &GetMajor() const { return mMajor; }

protected:
	QString mMajor;

	Global();
	~Global();


};

#endif