package com.test.helloservlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Refresh
 */
@WebServlet("/Refresh")
public class Refresh extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public Refresh() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// 设置刷新自动加载时间为 5 秒
		response.setIntHeader("Refresh", 5);
		// 设置响应内容类型
		response.setContentType("text/html;charset=UTF-8");

		// 使用默认时区和语言环境获得一个日历
		Calendar cale = Calendar.getInstance();
		// 将Calendar类型转换成Date类型
		Date tasktime = cale.getTime();
		// 设置日期输出的格式
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		// 格式化输出
		String nowTime = df.format(tasktime);
		PrintWriter out = response.getWriter();
		String title = "自动刷新 Header 设置 - 菜鸟教程实例";
		String docType = "<!DOCTYPE html>\n";
		out.println(
				docType + "<html>\n" + "<head><title>" + title + "</title></head>\n" + "<body bgcolor=\"#f0f0f0\">\n"
						+ "<h1 align=\"center\">" + title + "</h1>\n" + "<p>当前时间是：" + nowTime + "</p>\n");

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
