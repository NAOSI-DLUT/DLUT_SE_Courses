package com.servlet;

import javax.servlet.http.*;
import javax.servlet.ServletException;
import java.io.PrintWriter;
import java.io.IOException;

public class ServiceServlet extends HttpServlet {

    public void service(HttpServletRequest request,
            HttpServletResponse response) throws ServletException,
            IOException {
        //set MIME type for HTTP header
        response.setContentType("text/plain");

        //get a handle to the output stream
        PrintWriter out = response.getWriter();

        //determine type of request
        if (request.getMethod().equalsIgnoreCase("GET")) {
            out.println("GET request handled by the service() method");
        } else //not a GET request
        {
            //send an error to the client since only GET is supported
            response.sendError(HttpServletResponse.SC_BAD_REQUEST);
             //out.println("POST request handled by the service() method");
        }

        out.close(); //always close the output stream

    }
}