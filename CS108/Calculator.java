/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.calculator;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.io.*;

/**
 *
 * @author Lance Stephen L. Bronzal
 * BUCS BSCS 2B
 */
public class Calculator {

    public static void main(String[] args) {
        
        
        JFrame jFrame = new JFrame("Calculator");
        
        JTextField txtActiveLine = new JTextField("");
        JTextField txtPassiveLine = new JTextField("");
        JTextField txtHistoryLine1 = new JTextField("");
        JTextField txtHistoryLine2 = new JTextField("");
        JTextField txtHistoryLine3 = new JTextField("");
        JTextField txtHistoryLine4 = new JTextField("");
        JTextField txtHistoryLine5 = new JTextField("");
        JTextField txtHistoryLine6 = new JTextField("");
        JTextField txtHistoryLine7 = new JTextField("");
        JTextField txtHistoryLine8 = new JTextField("");
        
        JLabel lblHistory1 = new JLabel("Recent: ");
        JLabel lblHistory2 = new JLabel("2nd: ");
        JLabel lblHistory3 = new JLabel("3rd: ");
        JLabel lblHistory4 = new JLabel("4th: ");
        JLabel lblHistory5 = new JLabel("5th: ");
        JLabel lblHistory6 = new JLabel("6th:");
        JLabel lblHistory7 = new JLabel("7th:");
        JLabel lblHistory8 = new JLabel("8th:");
        
        JButton btnClear = new JButton("C");
        JButton btnNegate = new JButton("+/-");
        JButton btnBackspace = new JButton("Del");
        JButton btnDivide = new JButton("/");
        JButton btn7 = new JButton("7");
        JButton btn8 = new JButton("8");
        JButton btn9 = new JButton("9");
        JButton btnMultiply = new JButton("X");
        JButton btn4 = new JButton("4");
        JButton btn5 = new JButton("5");
        JButton btn6 = new JButton("6");
        JButton btnMinus = new JButton("-");
        JButton btn1 = new JButton("1");
        JButton btn2 = new JButton("2");
        JButton btn3 = new JButton("3");
        JButton btnAdd = new JButton("+");
        JButton btnPrevious = new JButton("Prev");
        JButton btn0 = new JButton("0");
        JButton btnDecimal = new JButton(".");
        JButton btnEqual = new JButton("=");
        JButton btnBack = new JButton("Back");
        
        txtActiveLine.setBounds(5, 55, 240, 50);
        txtActiveLine.setEditable(false);
        
        txtPassiveLine.setBounds(5, 5, 240, 45);
        txtPassiveLine.setEditable(false);
        
        txtHistoryLine1.setBounds(65, 5, 180, 40);
        txtHistoryLine1.setEditable(false);
        txtHistoryLine1.setVisible(false);
        lblHistory1.setBounds(5, 5, 60, 40);
        lblHistory1.setVisible(false);
        
        txtHistoryLine2.setBounds(65, 45, 180, 40);
        txtHistoryLine2.setEditable(false);
        txtHistoryLine2.setVisible(false);
        lblHistory2.setBounds(5, 45, 60, 40);
        lblHistory2.setVisible(false);
        
        txtHistoryLine3.setBounds(65, 85, 180, 40);
        txtHistoryLine3.setEditable(false);
        txtHistoryLine3.setVisible(false);
        lblHistory3.setBounds(5, 85, 60, 40);
        lblHistory3.setVisible(false);
        
        txtHistoryLine4.setBounds(65, 125, 180, 40);
        txtHistoryLine4.setEditable(false);
        txtHistoryLine4.setVisible(false);
        lblHistory4.setBounds(5, 125, 60, 40);
        lblHistory4.setVisible(false);
        
        txtHistoryLine5.setBounds(65, 165, 180, 40);
        txtHistoryLine5.setEditable(false);
        txtHistoryLine5.setVisible(false);
        lblHistory5.setBounds(5, 165, 60, 40);
        lblHistory5.setVisible(false);
        
        txtHistoryLine6.setBounds(65, 205, 180, 40);
        txtHistoryLine6.setEditable(false);
        txtHistoryLine6.setVisible(false);
        lblHistory6.setBounds(5, 205, 60, 40);
        lblHistory6.setVisible(false);
        
        txtHistoryLine7.setBounds(65, 245, 180, 40);
        txtHistoryLine7.setEditable(false);
        txtHistoryLine7.setVisible(false);
        lblHistory7.setBounds(5, 245, 60, 40);
        lblHistory7.setVisible(false);
        
        txtHistoryLine8.setBounds(65, 285, 180, 40);
        txtHistoryLine8.setEditable(false);
        txtHistoryLine8.setVisible(false);
        lblHistory8.setBounds(5, 285, 60, 40);
        lblHistory8.setVisible(false);
        
        btnClear.setBounds(5, 105, 60, 60);
        btnNegate.setBounds(65, 105, 60, 60);
        btnBackspace.setBounds(125, 105, 60, 60);
        btnDivide.setBounds(185, 105, 60, 60);
        btn7.setBounds(5, 165, 60, 60);
        btn8.setBounds(65, 165, 60, 60);
        btn9.setBounds(125, 165, 60, 60);
        btnMultiply.setBounds(185, 165, 60, 60);
        btn4.setBounds(5, 225, 60, 60);
        btn5.setBounds(65, 225, 60, 60);
        btn6.setBounds(125, 225, 60, 60);
        btnMinus.setBounds(185, 225, 60, 60);
        btn1.setBounds(5, 285, 60, 60);
        btn2.setBounds(65, 285, 60, 60);
        btn3.setBounds(125, 285, 60, 60);
        btnAdd.setBounds(185, 285, 60, 60);
        btnPrevious.setBounds(5, 345, 60, 60);
        btnBack.setBounds(5, 345, 80, 60);
        btnBack.setVisible(false);
        btn0.setBounds(65, 345, 60, 60);
        btnDecimal.setBounds(125, 345, 60, 60);
        btnEqual.setBounds(185, 345, 60, 60);
                
        jFrame.add(btnClear);
        jFrame.add(btnNegate);
        jFrame.add(btnBackspace);
        jFrame.add(btnDivide);
        jFrame.add(btn7);
        jFrame.add(btn8);
        jFrame.add(btn9);
        jFrame.add(btnMultiply);
        jFrame.add(btn4);
        jFrame.add(btn5);
        jFrame.add(btn6);
        jFrame.add(btnMinus);
        jFrame.add(btn1);
        jFrame.add(btn2);
        jFrame.add(btn3);
        jFrame.add(btnAdd);
        jFrame.add(btnPrevious);
        jFrame.add(btn0);
        jFrame.add(btnDecimal);
        jFrame.add(btnEqual);
        jFrame.add(btnBack);
        
        jFrame.add(txtActiveLine);
        jFrame.add(txtPassiveLine);
        
        jFrame.add(txtHistoryLine1);
        jFrame.add(txtHistoryLine2);
        jFrame.add(txtHistoryLine3);
        jFrame.add(txtHistoryLine4);
        jFrame.add(txtHistoryLine5);
        jFrame.add(txtHistoryLine6);
        jFrame.add(txtHistoryLine7);
        jFrame.add(txtHistoryLine8);
        
        jFrame.add(lblHistory1);
        jFrame.add(lblHistory2);
        jFrame.add(lblHistory3);
        jFrame.add(lblHistory4);
        jFrame.add(lblHistory5);
        jFrame.add(lblHistory6);
        jFrame.add(lblHistory7);
        jFrame.add(lblHistory8);
        
        jFrame.setSize(270, 450);
        jFrame.setLayout(null);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        btnClear.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                txtActiveLine.setText("");
                txtPassiveLine.setText("");
            }
        });
        btnNegate.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                double num1 = 0.0;
                input = txtActiveLine.getText();
                String inputArr[] = input.split(" ");
                int mark = 0;
                boolean isNegative = false;
                for (int i=input.length()-1; i>=0; i--){
                    if(inputArr.length<=1){
                        if(input.charAt(i)=='-'){
                            mark = i;
                            isNegative = true;
                            break;
                        }
                        else if(input.charAt(i)==' '){
                            break;
                        }
                    }
                    else {
                        if(i-2<0){
                            break;
                        }
                        else if(input.charAt(i)=='-' && (input.charAt(i-2)=='+' || input.charAt(i-2)=='-' || input.charAt(i-2)=='x' || input.charAt(i-2)=='/')){
                            mark = i;
                            isNegative = true;
                            break;
                        }
                    }
                }
                if (input.isEmpty()){
                    input+="-";
                }
                else if(isNegative==true){
                    if(mark>0){
                        if(mark==input.length()-1){
                            input = input.substring(0, input.length()-2);
                        }
                        else {
                            input = input.substring(0, mark) + input.substring(mark+1, input.length());
                        }
                    }
                    else {
                        input = input.substring(1, input.length());
                    }
                }
                else {
                    int temp = input.length()-inputArr[inputArr.length-1].length();
                    if(input.charAt(temp)=='+' || input.charAt(temp)=='-' || input.charAt(temp)=='x' || input.charAt(temp)=='/'){
                        input+=" -";
                    }
                    else {
                        input = input.substring(0, temp);
                        input+="-";
                        input+=inputArr[inputArr.length-1];
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btnBackspace.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    if(input.charAt(input.length()-1)==' ' || input.charAt(input.length()-2)==' '){
                        input = input.substring(0, input.length()-2);
                    }
                    else {
                        input = input.substring(0, input.length()-1);
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btnDivide.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x")){
                        input = input.substring(0, input.length()-1) + "/";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input = input.substring(0, input.length()-1) + "/";
                            }
                        }
                    }
                    else {
                        input+=" /";
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btn7.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "7";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 7";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 7";
                            }
                            else {
                                input+="7";
                            }
                        }
                        else {
                            input+="7";
                        }
                    }
                    else {
                        input+="7";
                    }
                }
                else {
                    input+="7";
                }
                txtActiveLine.setText(input);
            }
        });
        btn8.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "8";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 8";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 8";
                            }
                            else {
                                input+="8";
                            }
                        }
                        else {
                            input+="8";
                        }
                    }
                    else {
                        input+="8";
                    }
                }
                else {
                    input+="8";
                }
                txtActiveLine.setText(input);
            }
        });
        btn9.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "9";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 9";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 9";
                            }
                            else {
                                input+="9";
                            }
                        }
                        else {
                            input+="9";
                        }
                    }
                    else {
                        input+="9";
                    }
                }
                else {
                    input+="9";
                }
                txtActiveLine.setText(input);
            }
        });
        btnMultiply.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("/")){
                        input = input.substring(0, input.length()-1) + "x";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input = input.substring(0, input.length()-1) + "x";
                            }
                        }
                    }
                    else {
                        input+=" x";
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btn4.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "4";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 4";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 4";
                            }
                            else {
                                input+="4";
                            }
                        }
                        else {
                            input+="4";
                        }
                    }
                    else {
                        input+="4";
                    }
                }
                else {
                    input+="4";
                }
                txtActiveLine.setText(input);
            }
        });
        btn5.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "5";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 5";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 5";
                            }
                            else {
                                input+="5";
                            }
                        }
                        else {
                            input+="5";
                        }
                    }
                    else {
                        input+="5";
                    }
                }
                else {
                    input+="5";
                }
                txtActiveLine.setText(input);
            }
        });
        btn6.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "6";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 6";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 6";
                            }
                            else {
                                input+="6";
                            }
                        }
                        else {
                            input+="6";
                        }
                    }
                    else {
                        input+="6";
                    }
                }
                else {
                    input+="6";
                }
                txtActiveLine.setText(input);
            }
        });
        btnMinus.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input = input.substring(0, input.length()-1) + "-";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input = input.substring(0, input.length()-1) + "-";
                            }
                        }
                    }
                    else {
                        input+=" -";
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btn1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "1";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 1";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 1";
                            }
                            else {
                                input+="1";
                            }
                        }
                        else {
                            input+="1";
                        }
                    }
                    else {
                        input+="1";
                    }
                }
                else {
                    input+="1";
                }
                txtActiveLine.setText(input);
            }
        });
        btn2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "2";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 2";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 2";
                            }
                            else {
                                input+="2";
                            }
                        }
                        else {
                            input+="2";
                        }
                    }
                    else {
                        input+="2";
                    }
                }
                else {
                    input+="2";
                }
                txtActiveLine.setText(input);
            }
        });
        btn3.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("0")){
                        input = input.substring(0, input.length()-1) + "3";
                    }
                    else if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 3";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 3";
                            }
                            else {
                                input+="3";
                            }
                        }
                        else {
                            input+="3";
                        }
                    }
                    else {
                        input+="3";
                    }
                }
                else {
                    input+="3";
                }
                txtActiveLine.setText(input);
            }
        });
        btnAdd.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input = "0";
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input = input.substring(0, input.length()-1) + "+";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input = input.substring(0, input.length()-1) + "+";
                            }
                        }
                    }
                    else {
                        input+=" +";
                    }
                }
                txtActiveLine.setText(input);
            }
        });
        btn0.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                Double num1 = 0.0;
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 0";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 0";
                            }
                            else {
                                input+="0";
                            }
                        }
                        else {
                            input+="0";
                        }
                    }
                    else {
                        num1 = Double.parseDouble(inputArr[inputArr.length-1]);
                        boolean hasDecimal = false;
                        for(int i=0; i<inputArr[inputArr.length-1].length(); i++){
                            if(inputArr[inputArr.length-1].charAt(i)=='.'){
                                hasDecimal=true;
                                break;
                            }
                        }
                        if(hasDecimal==false){
                            if (num1!=0){
                                input+="0";
                            }
                        }
                        else {
                            input+="0";
                        }
                    }
                }
                else {
                    input+="0";
                }
                txtActiveLine.setText(input);
            }
        });
        btnDecimal.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                Double num1 = 0.0;
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    String inputArr[] = input.split(" ");
                    if(inputArr[inputArr.length-1].equals("+") || inputArr[inputArr.length-1].equals("x") || inputArr[inputArr.length-1].equals("/")){
                        input+=" 0.";
                    }
                    else if(inputArr[inputArr.length-1].equals("-")){
                        if(inputArr.length > 1){
                            if(!inputArr[inputArr.length-2].equals("+") && !inputArr[inputArr.length-2].equals("-") && !inputArr[inputArr.length-2].equals("x") && !inputArr[inputArr.length-2].equals("/")){
                                input+=" 0.";
                            }
                            else {
                                input+="0.";
                            }
                        }
                        else {
                            input+="0.";
                        }
                    }
                    else {
                        boolean hasDecimal = false;
                        for(int i=0; i<inputArr[inputArr.length-1].length(); i++){
                            if(inputArr[inputArr.length-1].charAt(i)=='.'){
                                hasDecimal=true;
                                break;
                            }
                        }
                        if(hasDecimal==false){
                            input+=".";
                        }
                    }
                }
                else {
                    input+="0.";
                }
                txtActiveLine.setText(input);
            }
        });
        btnEqual.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                String input="";
                Double num1 = 0.0, num2 = 0.0, ans = 0.0, temp = 0.0;
                int countedLength = 0, start = 0;
                boolean unitary = true;
                input = txtActiveLine.getText();
                if(!input.isEmpty()){
                    txtPassiveLine.setText(input+" =");
                    String inputArr[] = input.split(" ");
                    if(inputArr.length%2!=0){
                        countedLength = inputArr.length;
                    }
                    else {
                        countedLength = inputArr.length-1;
                    }
                    if(countedLength>1){
                        for(int i=1; i<countedLength; i+=2){
                            if(inputArr[i].equals("x")){
                                num1 = Double.parseDouble(inputArr[i-1]);
                                num2 = Double.parseDouble(inputArr[i+1]);
                                temp = num1 * num2;
                                inputArr[i-1] = Double.toString(temp);
                                inputArr[i+1] = Double.toString(temp);
                                inputArr[i] = "=";
                            }
                            if(inputArr[i].equals("/")){
                                num1 = Double.parseDouble(inputArr[i-1]);
                                num2 = Double.parseDouble(inputArr[i+1]);
                                temp = num1 / num2;
                                inputArr[i-1] = Double.toString(temp);
                                inputArr[i+1] = Double.toString(temp);
                                inputArr[i] = "=";
                            }
                        }
                        for(int i=1; i<countedLength; i+=2){
                            if(!inputArr[i].equals("=")){
                                ans = Double.parseDouble(inputArr[i-1]);
                                start = i;
                                unitary = false;
                                break;
                            }
                        }
                        if(unitary==true){
                            ans = Double.parseDouble(inputArr[countedLength-1]);
                        }
                        else {
                            for(int i=start; i<countedLength;){
                                int j = i + 2;
                                for(; j<countedLength; j+=2){
                                    if(!inputArr[j].equals("=")){
                                        break;
                                    }
                                }
                                num2 = Double.parseDouble(inputArr[j-1]);
                                if(inputArr[i].equals("+")){
                                    ans+=num2;
                                }
                                else if (inputArr[i].equals("-")){
                                    ans-=num2;
                                }
                                i = j;
                            } 
                        }
                        input = Double.toString(ans);
                    }
                    else {
                        ans = Double.parseDouble(inputArr[0]);
                        input = Double.toString(ans);
                    }
                }
                else {
                    input+="0";
                    txtPassiveLine.setText(input+" =");
                }
                txtActiveLine.setText(input);
                
                txtHistoryLine8.setText(txtHistoryLine7.getText());
                txtHistoryLine7.setText(txtHistoryLine6.getText());
                txtHistoryLine6.setText(txtHistoryLine5.getText());
                txtHistoryLine5.setText(txtHistoryLine4.getText());
                txtHistoryLine4.setText(txtHistoryLine3.getText());
                txtHistoryLine3.setText(txtHistoryLine2.getText());
                txtHistoryLine2.setText(txtHistoryLine1.getText());
                txtHistoryLine1.setText(txtPassiveLine.getText() + input);
            }
        });
        btnPrevious.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                btnPrevious.setVisible(false);
                btnBack.setVisible(true);
                txtHistoryLine1.setVisible(true);
                txtHistoryLine2.setVisible(true);
                txtHistoryLine3.setVisible(true);
                txtHistoryLine4.setVisible(true);
                txtHistoryLine5.setVisible(true);
                txtHistoryLine6.setVisible(true);
                txtHistoryLine7.setVisible(true);
                txtHistoryLine8.setVisible(true);
                lblHistory1.setVisible(true);
                lblHistory2.setVisible(true);
                lblHistory3.setVisible(true);
                lblHistory4.setVisible(true);
                lblHistory5.setVisible(true);
                lblHistory6.setVisible(true);
                lblHistory7.setVisible(true);
                lblHistory8.setVisible(true);
                
                txtActiveLine.setVisible(false);
                txtPassiveLine.setVisible(false);
                btnClear.setVisible(false);
                btnNegate.setVisible(false);
                btnBackspace.setVisible(false);
                btnDivide.setVisible(false);
                btn7.setVisible(false);
                btn8.setVisible(false);
                btn9.setVisible(false);
                btnMultiply.setVisible(false);
                btn4.setVisible(false);
                btn5.setVisible(false);
                btn6.setVisible(false);
                btnMinus.setVisible(false);
                btn1.setVisible(false);
                btn2.setVisible(false);
                btn3.setVisible(false);
                btnAdd.setVisible(false);
                btn0.setVisible(false);
                btnDecimal.setVisible(false);
                btnEqual.setVisible(false);
            }
        });
        btnBack.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                btnPrevious.setVisible(true);
                btnBack.setVisible(false);
                txtHistoryLine1.setVisible(false);
                txtHistoryLine2.setVisible(false);
                txtHistoryLine3.setVisible(false);
                txtHistoryLine4.setVisible(false);
                txtHistoryLine5.setVisible(false);
                txtHistoryLine6.setVisible(false);
                txtHistoryLine7.setVisible(false);
                txtHistoryLine8.setVisible(false);
                lblHistory1.setVisible(false);
                lblHistory2.setVisible(false);
                lblHistory3.setVisible(false);
                lblHistory4.setVisible(false);
                lblHistory5.setVisible(false);
                lblHistory6.setVisible(false);
                lblHistory7.setVisible(false);
                lblHistory8.setVisible(false);
                
                txtActiveLine.setVisible(true);
                txtPassiveLine.setVisible(true);
                btnClear.setVisible(true);
                btnNegate.setVisible(true);
                btnBackspace.setVisible(true);
                btnDivide.setVisible(true);
                btn7.setVisible(true);
                btn8.setVisible(true);
                btn9.setVisible(true);
                btnMultiply.setVisible(true);
                btn4.setVisible(true);
                btn5.setVisible(true);
                btn6.setVisible(true);
                btnMinus.setVisible(true);
                btn1.setVisible(true);
                btn2.setVisible(true);
                btn3.setVisible(true);
                btnAdd.setVisible(true);
                btn0.setVisible(true);
                btnDecimal.setVisible(true);
                btnEqual.setVisible(true);
            }
        });
    }
}
