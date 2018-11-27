#pragma once

#include <string>
#include <map>

#include "../jsonparser.h"
#include "../specification.h"

namespace stubgenerator
{
    typedef std::map<std::string, jsonrpc::jsontype_t> parameterNameList_t;
    typedef std::vector<jsonrpc::jsontype_t> parameterPositionList_t;

    typedef enum {PARAMS_BY_NAME, PARAMS_BY_POSITION} parameterDeclaration_t;

    class Procedure
    {
        public:
            Procedure(const std::string& name);

            //Various get methods.
            const parameterNameList_t&      GetParameters               () const;
			jsonrpc::procedure_t            GetProcedureType            () const;
            const std::string&              GetProcedureName            () const;
			jsonrpc::jsontype_t             GetReturnType               () const;
            parameterDeclaration_t          GetParameterDeclarationType () const;

            void                            SetProcedureType            (jsonrpc::procedure_t type);
            void                            SetReturnType               (jsonrpc::jsontype_t type);
            void                            SetParameterDeclarationType (parameterDeclaration_t type);

            void AddParameter(const std::string& name, jsonrpc::jsontype_t type);

            std::string ToString();


        private:

            /**
             * Each Procedure should have a name.
             */
            std::string                 procedureName;

            /**
             * This map represents all necessary Parameters of each Procedure.
             * The string represents the name of each parameter and JsonType the type it should have.
             */
            parameterNameList_t         parametersName;

            /**
             * This vector holds all parametertypes by position.
             */
            parameterPositionList_t     parametersPosition;

            /**
             * @brief defines whether the procedure is a method or a notification
             */
			jsonrpc::procedure_t                 procedureType;

            /**
             * @brief this field is only valid if procedure is of type method (not notification).
             */
			jsonrpc::jsontype_t                  returntype;

            /**
             * @brief paramDeclaration this field defines if procedure uses named or positional parameters.
             */
            parameterDeclaration_t      paramDeclaration;

            bool ValidateSingleParameter        (jsonrpc::jsontype_t expectedType, const Json::Value &value) const;
    };

} /* namespace jsonrpc */
