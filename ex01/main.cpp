/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:43 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/20 09:49:34 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ctype.h>
#include<string>
#include<iostream>
#include<stack>

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

int main(int ac, char **av){
    if (ac == 2){
        std::string s(av[1]), o("-+/*");
        std::stack<int> stk;
        if (s.empty()){
            std::cerr << "Error : Empty argument" << std::endl;
            return 1;
        }
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ')
                continue;
            if (!isdigit(s[i]) && o.find(s[i]) == std::string::npos){
                std::cerr << "Error : Invalid input " << s << std::endl;
                return 1; 
            }
            if (isdigit(s[i]))
                stk.push(s[i] - '0');
            else if (stk.size() >= 2){
                int t = stk.top();
                stk.pop();
                stk.top() = doop(stk.top(), t, s[i]);
            }
            else{
                std::cerr << "Error : Can't do the " << s[i] << " Operation Because the stack does not have enough numbers" << std::endl;
                return 1;
            }
        }
        if (stk.size() > 1){
            std::cerr << "Error : They were not enough operation it still more than one number in the stack" << std::endl;
            return 1;
        }
        std::cout << stk.top() << std::endl;
        return 0;
    }
    else{
        std::cerr << "Error : Invalid number of argument" << std::endl;
        return 1;
    }
}
