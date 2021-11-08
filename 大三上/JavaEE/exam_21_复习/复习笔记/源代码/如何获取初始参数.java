/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.servlet;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author yuren
 */
public class InitParamServlet extends HttpServlet {

    ServletConfig myconfig;

    public void init(ServletConfig config) throws ServletException {
        super.init(config); //initialize the config object and stores it.
        myconfig = config;
    }

    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/pdf");
        ServletOutputStream out = response.getOutputStream();
        File pdf = null;
        BufferedInputStream buf = null;
        //获取初始化参数
        String pdfDir = myconfig.getInitParameter("FilePath");
        if (pdfDir == null || pdfDir.equals("")) {
            throw new ServletException("Servlet params wrongs");
        }
        try {
            pdf = new File(pdfDir + "sample.pdf");
            response.setContentLength((int) pdf.length());
            FileInputStream input = new FileInputStream(pdf);
            buf = new BufferedInputStream(input);
            int readBytes = 0;
            //从文件读取数据并写入ServletOutputStream
            while ((readBytes = buf.read()) != -1) {
                out.write(readBytes);
            }
        } catch (IOException e) {
            System.out.println("file not found.");
        } finally {
            if (out != null) {
                out.close();
            }
            if (buf != null) {
                buf.close();
            }
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet 方法。单击左侧的 + 号以编辑代码。">
    /** 
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Returns a short description of the servlet.
     */
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>
}
