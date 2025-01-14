package com.test.login.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.test.login.entity.Users;
import com.test.login.service.UserService;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public LoginServlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// ������Ӧͷ
		response.setContentType("text/html;charset=UTF-8");

		String html = "";
		String name = request.getParameter("name");
		String pwd = request.getParameter("pwd");
		UserService us = new UserService();
		Users users = us.login(name, pwd);

		if (users != null) {
			request.setAttribute("name", users.getUsername());
			request.getRequestDispatcher("/SuccessJsp").forward(request, response);
		} else {
			request.getRequestDispatcher("/FailJsp").forward(request, response);
		}
		response.getWriter().print(html);

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
