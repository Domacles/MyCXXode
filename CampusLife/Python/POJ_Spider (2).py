#!/usr/bin/python3
# -*- coding: utf-8 -*-

import urllib.request
import html.parser
import xlwt3


class MyHtmlParser(html.parser.HTMLParser):

    """Override the parser class"""

    def Myinit(self, filename):
        self.flag = 0
        self.f = open(filename, 'a', encoding='utf - 8')

    def handle_starttag(self, tag, attrs):
        """ Overridable -- handle start tag """
        if tag == 'a':
            for e in attrs:
                if e[0] == 'href':
                    if e[1][:10] == 'problem?id':
                        self.flag = 1
                        try:
                            self.f.write(e[1][11:] + '\n')
                            print('save ' + e[1][11:])
                        except:
                            print('Error at writing in file 1')
                    elif e[1][:24] == 'problemstatus?problem_id':
                        self.flag = 2

    def handle_data(self, data):
        """ Overridable -- handle data"""
        if self.flag != 0:
            try:
                self.f.write(data + '\n')
                print('save ' + data)
            except:
                print('Error at writing in file 2')
        self.flag = 0


def UrlDownload(url, filename):
    try:
        print('start UrlDownload ' + url)
        Html = urllib.request.urlopen(url).read()
        # save in file
        # HtmlFile = open(filename, 'w', encoding='utf - 8')
        # HtmlFile.write((Html).decode('utf-8', 'ignore'))
        # HtmlFile.close()
        return Html
    except:
        print('Error at UrlDownload!!')


def Recognize(html, outfile):
    print('start recognition...')
    myHtmlParser = MyHtmlParser()
    myHtmlParser.Myinit(outfile)
    myHtmlParser.feed(html.decode('utf-8'))


def SaveConsequence(infile, outfile, url):
    print('start SaveConsequence...')
    f = open(infile, 'r', encoding='utf - 8')
    wb = xlwt3.Workbook()
    ws = wb.add_sheet('problems')
    ws.write(0, 0, 'ID')
    ws.write(0, 1, 'Title')
    ws.write(0, 2, 'ACnum')
    ws.write(0, 3, 'URL')
    i = 0
    r = 1
    for s in f:
        if i == 0:
            ws.write(r, 0, s)
            ws.write(r, 3, url + s)
        elif i == 1:
            ws.write(r, 1, s)
        elif i == 2:
            ws.write(r, 2, int(s))
            r = r + 1
            i = -1
        i = i + 1
    wb.save(outfile)


if __name__ == '__main__':
    print('Run...')
    # this file save problems ID Title ACnum
    problemfile = 'problems.txt'
    # this file save Consequence of recognition
    outfile = 'volumes.xls'
    for i in range(1, 32):
        # POJ problems URL
        url = 'http://poj.org/problemlist?volume=' + str(i)
        # Download Html
        sfile = 'volume_' + str(i) + '.Html'
        # Download
        html = UrlDownload(url, sfile)
        # Recognize
        Recognize(html, problemfile)
    # Save
    SaveConsequence(problemfile, outfile, 'http://poj.org/problem?id=')
