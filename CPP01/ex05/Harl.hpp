/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:19:24 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 18:51:35 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>


class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
public:
    void complain(std::string level);
};

#endif