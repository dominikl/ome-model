/*
 * ome.xml.r201004.Polyline
 *
 *-----------------------------------------------------------------------------
 *
 *  Copyright (C) @year@ Open Microscopy Environment
 *      Massachusetts Institute of Technology,
 *      National Institutes of Health,
 *      University of Dundee,
 *      University of Wisconsin-Madison
 *
 *
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 2.1 of the License, or (at your option) any later version.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *-----------------------------------------------------------------------------
 */

/*-----------------------------------------------------------------------------
 *
 * THIS IS AUTOMATICALLY GENERATED CODE.  DO NOT MODIFY.
 * Created by callan via xsd-fu on 2010-04-22 12:27:38+0100
 *
 *-----------------------------------------------------------------------------
 */

package ome.xml.r201004;

import java.util.ArrayList;
import java.util.List;


import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import ome.xml.r201004.enums.*;

public class Polyline extends Shape
{
	// -- Constants --

	public static final String NAMESPACE = "http://www.openmicroscopy.org/Schemas/ROI/2010-04";

	// -- Instance variables --

	// Property
	private String points;

	// Property
	private Boolean closed;

	// -- Constructors --

	/** Default constructor. */
	public Polyline()
	{
		super();
	}

	/** 
	 * Constructs Polyline recursively from an XML DOM tree.
	 * @param element Root of the XML DOM tree to construct a model object
	 * graph from.
	 * @throws EnumerationException If there is an error instantiating an
	 * enumeration during model object creation.
	 */
	public Polyline(Element element) throws EnumerationException
	{
		update(element);
	}

	/** 
	 * Updates Polyline recursively from an XML DOM tree. <b>NOTE:</b> No
	 * properties are removed, only added or updated.
	 * @param element Root of the XML DOM tree to construct a model object
	 * graph from.
	 * @throws EnumerationException If there is an error instantiating an
	 * enumeration during model object creation.
	 */
	public void update(Element element) throws EnumerationException
	{	
		super.update(element);
		String tagName = element.getTagName();
		if (!"Polyline".equals(tagName))
		{
			System.err.println(String.format(
					"WARNING: Expecting node name of Polyline got %s",
					tagName));
			// TODO: Should be its own Exception
			//throw new RuntimeException(String.format(
			//		"Expecting node name of Polyline got %s",
			//		tagName));
		}
		if (element.hasAttribute("Points"))
		{
			// Attribute property Points
			setPoints(String.valueOf(
					element.getAttribute("Points")));
		}
		if (element.hasAttribute("Closed"))
		{
			// Attribute property Closed
			setClosed(Boolean.valueOf(
					element.getAttribute("Closed")));
		}
	}

	// -- Polyline API methods --

	// Property
	public String getPoints()
	{
		return points;
	}

	public void setPoints(String points)
	{
		this.points = points;
	}

	// Property
	public Boolean getClosed()
	{
		return closed;
	}

	public void setClosed(Boolean closed)
	{
		this.closed = closed;
	}

	public Element asXMLElement(Document document)
	{
		return asXMLElement(document, null);
	}

	protected Element asXMLElement(Document document, Element Polyline_element)
	{
		// Creating XML block for Polyline
		if (Polyline_element == null)
		{
			Polyline_element =
					document.createElementNS(NAMESPACE, "Polyline");
		}

		if (points != null)
		{
			// Attribute property Points
			Polyline_element.setAttribute("Points", points.toString());
		}
		if (closed != null)
		{
			// Attribute property Closed
			Polyline_element.setAttribute("Closed", closed.toString());
		}
		return super.asXMLElement(document, Polyline_element);
	}
}
