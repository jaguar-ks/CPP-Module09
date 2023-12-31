/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:30:35 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/21 04:39:05 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int doop(int a, int b, char op){
    if (op == '*')
        return a*b;
    else if (op == '/'){
        if (!b){
            std::cerr << "Error : Can't devide by 0" << std::endl;
            exit(1);
        }
        return a/b;
    }
    else if (op == '-')
        return a-b;
    else
        return a+b;
}
