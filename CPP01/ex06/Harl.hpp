/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:23:18 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:23:35 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    // Helper method to convert level string to enum
    int getLevelIndex(std::string level);

public:
    void complain(std::string level);
    void filterComplain(std::string minLevel);
};

#endif