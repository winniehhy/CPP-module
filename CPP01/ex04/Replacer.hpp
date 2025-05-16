/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:07:08 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 16:09:38 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Replacer {
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    
public:
    Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
    ~Replacer();
    
    bool replace();
};

#endif