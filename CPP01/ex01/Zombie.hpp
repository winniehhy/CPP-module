/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:44:34 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:53:17 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

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

// Function to create a horde of zombies
Zombie* zombieHorde(int N, std::string name);

#endif