#ifndef SPFILEPARSER_H
#define SPFILEPARSER_H

#include <QString>
#include <QFile>
#include "data.h"

extern const QStringList SurfaceTypes;
extern const QStringList RoofTypes;

/**
 * @brief The SPFile reader.
 */
/*!
 * The SPFile class contains one private data member:\n
 * dat                  : A reference to the data stored in the main program.\n\n
 */
class SPFileParser
{
public:
    /**
     * @brief Default constructor initialized with a refrence to the internal data of the main program.
     * @param dat A reference to the data in the main program.
     */
    SPFileParser(class data& dat);

    /**
     * @brief Read an sp file.
     * @param filedir Directory do the file to be read.
     * @param ErrorMessage A QStringList that contains the error message.
     * @return Returns true if the read was successful, else turns false.
     */
    bool read(const QString& filedir, QStringList& ErrorMessage) const;
private:
    class data& dat;
};

#endif // SPFILEPARSER_H
