/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:44 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 13:32:32 by hheng            ###   ########.fr       */
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
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif