#ifndef CONTRACT
#define CONTRACT

#include <vector>
#include <string>

class Contract {
    const std::size_t unique_id;
    std::string company_name, company_CIF;
    static std::size_t next_unique_id;
public:
    Contract();
    Contract(std::string company_name, std::string company_CIF);
    Contract(const Contract &other);
    Contract &operator=(const Contract &other);
    [[nodiscard]] const std::string &get_company_name() const;
    [[nodiscard]] const std::string &get_company_CIF() const;
};

#endif //CONTRACT
