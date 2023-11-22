/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:59:36 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/22 11:02:59 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"
#include <_ctype.h>
#include <climits>
#include <cstdlib>
#include <sys/_types/_size_t.h>

bool valid(std::string s){
    for (size_t i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            return false;
    if (atol(s.c_str()) > INT_MAX)
        return false;
    return true;
}
