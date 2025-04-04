/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:11:11 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 14:47:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    
    void announce() const;
    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
